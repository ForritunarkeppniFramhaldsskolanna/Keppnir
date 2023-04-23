#!/usr/bin/python3
import sys
import random

TOP = 140.5
LEFT = 0
BOTTOM = 0
RIGHT = 70
RADIUS = 1
EPS = 5e-3

CENTER_X = LEFT + (RIGHT-LEFT)/2
CENTER_Y = BOTTOM + (TOP-BOTTOM)/2

def random_x():
    return round(random.uniform(LEFT+RADIUS, RIGHT-RADIUS), 3)

def random_y():
    return round(random.uniform(BOTTOM+RADIUS, TOP-RADIUS), 3)

def get_random_ball(color):
    return color, random_x(), random_y()

def collides(a, b):
    dx = a[1] - b[1]
    dy = a[2] - b[2]
    return dx**2 + dy**2 <= (2*RADIUS)**2
        
def add_random_ball(color, balls, f=lambda x: True):
    while True:
        ball = get_random_ball(color)
        if not any(collides(ball, other) for other in balls) and f(ball):
            break
    balls.append(ball)


def get_pyramid(rows, x, y):
    x_step = 2*RADIUS + EPS
    y_step = RADIUS * 3**0.5 + EPS
    res = []
    for row in range(rows):
        for j in range(row+1):
            res.append(('red', x + x_step * (j - row/2), y + y_step * row))
    return res

def proportional_distance(px, py):
    return round(LEFT + (RIGHT - LEFT) * px, 3), round(BOTTOM + (TOP - BOTTOM) * py, 3)

random.seed(int(sys.argv[-1]))

setup_type = sys.argv[1]
min_n = int(sys.argv[2])
max_n = int(sys.argv[3])
angle_type = sys.argv[4]
bounce_type = sys.argv[5]
#result_type = sys.argv[6]
minimum_power = 100 if setup_type == "snooker_start" else 0

assert angle_type in ["axis_aligned", "any"]
assert bounce_type in ["bounce", "no_bounce"]
#assert result_type in ["random", "hit", "foul", "miss"]

def add_white_ball(balls, on_color):
    if setup_type == "snooker_start":
        def in_the_d(ball):
            baulk_point = proportional_distance(1/2, 1/5)
            dx = ball[1] - baulk_point[0]
            dy = ball[2] - baulk_point[1]
            return ball[2] <= baulk_point[1] and dx**2 + dy**2 <= proportional_distance(1/6, 0)[0]**2

        add_random_ball("white", balls, in_the_d)
    else:
        add_random_ball("white", balls)

def get_random_force_vector(white_ball):
    color, x, y = white_ball
    vx, vy = 0, 0
    vx_min = -1000 if bounce_type == "bounce" else LEFT - (x - RADIUS - EPS)
    vx_max =  1000 if bounce_type == "bounce" else RIGHT - (x + RADIUS + EPS)
    vy_min = -1000 if bounce_type == "bounce" else BOTTOM - (y - RADIUS - EPS)
    vy_max =  1000 if bounce_type == "bounce" else TOP - (y + RADIUS + EPS)
    while vx**2 + vy**2 < minimum_power**2 + EPS or (setup_type == "snooker_start" and vy < abs(vx)):
        if angle_type == "axis_aligned":
            if random.randint(0, 1):
                vx = round(random.uniform(vx_min, vx_max), 3)
                vy = 0
            else:
                vy = round(random.uniform(vy_min, vy_max), 3)
                vx = 0
        elif angle_type == "any":
                vx = round(random.uniform(vx_min, vx_max), 3)
                vy = round(random.uniform(vy_min, vy_max), 3)
        else:
            assert False
    return vx, vy

assert min_n >= 2
assert max_n <= 22

balls = []
if setup_type == "random":
    n = random.randint(min_n, max_n)
    colors = ['white', 'black', 'pink', 'blue', 'brown', 'green', 'yellow'] + ['red']*15
    for color in colors[1:n]:
        add_random_ball(color, balls)
    on_color = random.choice(colors[1:n])
elif setup_type == "snooker_start":
    n = 22
    black_spot = proportional_distance(1/2, 10/11)
    black_ball = ('black',) +  black_spot
    
    pink_spot = proportional_distance(1/2, 3/4)
    pink_ball = ('pink',) + pink_spot

    blue_ball = ('blue',) + proportional_distance(1/2, 1/2)
    brown_ball = ('brown',) + proportional_distance(1/2, 1/5)
    green_ball = ('green',) + proportional_distance(1/3, 1/5)
    yellow_ball = ('yellow',) + proportional_distance(2/3, 1/5)

    balls.extend([black_ball, pink_ball, blue_ball, brown_ball, green_ball, yellow_ball])
    
    pyramid_spot = pink_spot[0], pink_spot[1] + (2*RADIUS + 0.25)
    balls.extend(get_pyramid(5, *pyramid_spot))
    on_color = 'red'
else:
    assert False
add_white_ball(balls, on_color)
vx, vy = get_random_force_vector(balls[-1])

sys.stdout.write("{}\n".format(n))
for ball in balls:
    sys.stdout.write("{} {:.3f} {:.3f}\n".format(*ball))
sys.stdout.write("{}\n".format(on_color))
sys.stdout.write("{:.3f} {:.3f}\n".format(vx, vy))

#!/usr/bin/python3
import math
import sys
from PIL import Image, ImageDraw


TOP = 140.5
LEFT = 0.0
BOTTOM = 0.0
RIGHT = 70.0
RADIUS = 1.0
EPS = 1e-4

def sgn(x):
    return -1 if x < 0 else 1

def progress(x, a, b):
    return (x-a)/(b-a)

def circle_line_intersect(x_1, y_1, x_2, y_2, r, o_x = 0, o_y = 0):
    x_1 -= o_x
    x_2 -= o_x
    y_1 -= o_y
    y_2 -= o_y

    d_x = x_2 - x_1
    d_y = y_2 - y_1
    d_r_2 = d_x**2 + d_y**2
    d_r = d_r_2 ** 0.5
    D = x_1 * y_2 - x_2 * y_1
    discriminant = r ** 2 * d_r ** 2 - D ** 2
    if discriminant < EPS:
        return [], []
    elif abs(discriminant) <= EPS:
        return [(D * d_y) / d_r_2 + o_x], [(-D * d_x) / d_r_2 + o_y]
    else:
        diffx = sgn(d_y) * d_x * discriminant ** 0.5
        diffy = abs(d_y) * discriminant ** 0.5
        xs, ys = [], []
        for i in range(-1, 2, 2):
            xs.append((D * d_y + i*diffx) / d_r_2 + o_x)
            ys.append((-D * d_x + i*diffy) / d_r_2 + o_y)
        return xs, ys

class Hit:
    def __init__(self, time, x_pos, y_pos, x_multiplier, y_multiplier):
        self.time = time
        self.x_pos = x_pos
        self.y_pos = y_pos
        self.x_multiplier = x_multiplier
        self.y_multiplier = y_multiplier

    def __lt__(self, other):
        return self.time < other.time

    def __repr__(self):
        return "{}({},{},{},{},{})".format(self.__class__.__name__, self.time, self.x_pos, self.y_pos, self.x_multiplier, self.y_multiplier)

class Ball:
    def __init__(self, color, x, y):
        self.color = color
        self.x = x
        self.y = y
        self.radius = RADIUS
        self.path = [(x, y)]

    def time_till_cushion_hit(self, move_x, move_y):
        return min(self.time_till_cushion_hit_x(move_x, move_y), self.time_till_cushion_hit_y(move_x, move_y))

    def time_till_cushion_hit_x(self, move_x, move_y):
        target = LEFT + self.radius if move_x < 0 else RIGHT - self.radius
        dx = target - self.x
        t = dx / move_x if abs(move_x) >= EPS else float('inf')
        dy = t * move_y
        return Hit(t, self.x+dx, self.y+dy, -1, 1)

    def time_till_cushion_hit_y(self, move_x, move_y):
        target = BOTTOM + self.radius if move_y < 0 else TOP - self.radius
        dy = target - self.y
        t = dy / move_y if abs(move_y) >= EPS else float('inf')
        dx = t * move_x
        return Hit(t, self.x + dx, self.y + dy, 1, -1)

    def time_of_collision_while_moving(self, other, move_x, move_y):
        x_1 = self.x
        x_2 = self.x + move_x
        y_1 = self.y
        y_2 = self.y + move_y
        xs, ys = circle_line_intersect(x_1, y_1, x_2, y_2, self.radius + other.radius, other.x, other.y)
        #print(other.color, other.x, other.y, x_1, y_1, x_2, y_2, xs, ys)
        ans = float('inf')
        for x, y in zip(xs, ys):
            t = progress(y, y_1, y_2) if abs(x_2 - x_1) < EPS else progress(x, x_1, x_2)
            if -EPS < t < 1+EPS:
                ans = min((t, ans))
        return ans

    def move(self, new_x, new_y):
        self.x = new_x
        self.y = new_y
        self.path.append((self.x, self.y))

    def find_first_ball_hit(self, move_x, move_y, balls):
        while abs(move_x) > EPS or abs(move_y) > EPS:
            hit = self.time_till_cushion_hit(move_x, move_y)
            remove_x = min(1.0, hit.time) * move_x
            remove_y = min(1.0, hit.time) * move_y
            move_x -= remove_x
            move_y -= remove_y
            move_x *= hit.x_multiplier
            move_y *= hit.y_multiplier
            collide_ball = None
            first_collide_time = float('inf')
            for ball in balls:
                collide_time = self.time_of_collision_while_moving(ball, remove_x, remove_y)
                if collide_time < first_collide_time:
                    collide_ball = ball
                    first_collide_time = collide_time
            if collide_ball is not None:
                self.move(self.x + remove_x*first_collide_time, self.y + remove_y*first_collide_time)
                return collide_ball
            self.move(self.x + remove_x, self.y + remove_y)
        return None
    
    def __repr__(self):
        return "{}({},{},{})".format(self.__class__.__name__, repr(self.color), self.x, self.y)

if __name__ == "__main__":
    filename = sys.argv[1]
    
    n = int(input())

    balls = []
    for i in range(n):
        color, x, y = input().split()
        x = float(x)
        y = float(y)
        if color == "white":
            white_ball = Ball(color, x, y)
        else:
            balls.append(Ball(color, x, y))

    on_color = input()
    move_x, move_y = map(float, input().split())

    hit_ball = white_ball.find_first_ball_hit(move_x, move_y, balls)

    # Values are tenths of inches
    SCALE = 20
    PLAYAREA_WIDTH, PLAYAREA_HEIGHT = 70*SCALE, int(140.5*SCALE)
    BOUND = 2*SCALE
    BALL_RADIUS = 1*SCALE
    BAULK_LINE_Y = BOUND + PLAYAREA_HEIGHT / 5
    CENTER_X = BOUND + PLAYAREA_WIDTH / 2
    IMAGE_WIDTH, IMAGE_HEIGHT = 2*BOUND + PLAYAREA_WIDTH, 2*BOUND + PLAYAREA_HEIGHT

    def draw_ball(draw, ball):
        tx = SCALE*ball.x + BOUND
        ty = SCALE*ball.y + BOUND
        sx = tx - BALL_RADIUS
        sy = ty - BALL_RADIUS
        ex = tx + BALL_RADIUS
        ey = ty + BALL_RADIUS
        draw.ellipse((sx, sy, ex, ey), fill=ball.color, outline="black")

    def draw_on_mark(draw, ball):
        tx = SCALE*ball.x + BOUND
        ty = SCALE*ball.y + BOUND
        draw.ellipse((tx-BALL_RADIUS/2, ty-BALL_RADIUS/2, tx+BALL_RADIUS/2, ty+BALL_RADIUS/2), fill="red")


    table = [(0, 0), (IMAGE_WIDTH, IMAGE_HEIGHT)]
    play_area = [(BOUND, BOUND), (BOUND + PLAYAREA_WIDTH, BOUND + PLAYAREA_HEIGHT)]
    baulk_line = [(BOUND, BAULK_LINE_Y), (BOUND + PLAYAREA_WIDTH, BAULK_LINE_Y)]
    d_radius = PLAYAREA_WIDTH/6
    d_boundary = [(CENTER_X - d_radius, BAULK_LINE_Y - d_radius), (CENTER_X + d_radius, BAULK_LINE_Y + d_radius)]
      
    # creating new Image object
    img = Image.new("RGBA", (IMAGE_WIDTH, IMAGE_HEIGHT))

    # create rectangle image
    draw = ImageDraw.Draw(img)
    draw.rectangle(table, fill="black")
    draw.rectangle(play_area, fill="#2c8257")
    draw.line(baulk_line, fill="grey", width=2)
    draw.arc(d_boundary, 180, 360, fill="grey", width=2)

    white_ball.x, white_ball.y = white_ball.path[0]
    draw_ball(draw, white_ball)
    for ball in balls:
        draw_ball(draw, ball)
    
    overlay = Image.new('RGBA', img.size, (0,0,0,0,))
    overlay_draw = ImageDraw.Draw(overlay)

    for (x, y) in white_ball.path[1:]:
        draw_ball(overlay_draw, Ball((255, 255, 255, 100), x, y))
    cue_ball_path = [(x*SCALE + BOUND, y*SCALE + BOUND) for (x, y) in white_ball.path]
    overlay_draw.line(cue_ball_path, fill=(255, 0, 0, 100), width=2, joint=True)
    for ball in balls:
        if ball.color == on_color:
            draw_on_mark(overlay_draw, ball)

    img = Image.alpha_composite(img, overlay)
    img = img.convert("RGB")
    img.save(filename, 'PNG')

#!/usr/bin/python3
import math

TOP = 140.5
BOT = 0
LEFT = 0
RIGHT = 70
RADIUS = 1.0
EPS = 1e-9

class Ball:
    def __init__(self, color, x, y):
        self.color = color
        self.x = x
        self.y = y
        self.radius = RADIUS

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

def find_first_hit(balls, white_ball, move_x, move_y):
    filtered_balls = []
    func = min
    keyfunc = None

    def get_keyfunc(distance, axis, other_axis):
        def f(val):
            axis_diff = abs(val.__getattribute__(axis) - white_ball.__getattribute__(axis))
            extra_other = (distance**2 - axis_diff**2)**0.5
            other_axis_diff = abs(val.__getattribute__(other_axis) - white_ball.__getattribute__(other_axis))
            return other_axis_diff - extra_other
        return f

    if move_x == 0:
        if move_y > 0:
            filtered_balls = [ball for ball in balls if abs(ball.x - white_ball.x) <= 2*RADIUS and ball.y > white_ball.y]
        else:
            filtered_balls = [ball for ball in balls if abs(ball.x - white_ball.x) <= 2*RADIUS and ball.y < white_ball.y]
        keyfunc = get_keyfunc(2*RADIUS, 'x', 'y')
    else:
        if move_x > 0:
            filtered_balls = [ball for ball in balls if abs(ball.y - white_ball.y) <= 2*RADIUS and ball.x > white_ball.x]
        else:
            filtered_balls = [ball for ball in balls if abs(ball.y - white_ball.y) <= 2*RADIUS and ball.x < white_ball.x]
        keyfunc = get_keyfunc(2*RADIUS, 'y', 'x')

    hit_ball = None
    if filtered_balls:
        if move_x == 0:
            hit_ball = func(filtered_balls, key=keyfunc)
        else:
            hit_ball = func(filtered_balls, key=keyfunc)

    if hit_ball is not None and keyfunc(hit_ball) > abs(move_x or move_y):
        hit_ball = None

    return hit_ball

def collide(white_ball, move_x, move_y):
    if move_x == 0:
        if move_y > 0:
            dist_to_edge = TOP - RADIUS - white_ball.y
        else:
            dist_to_edge = BOT + RADIUS - white_ball.y
        if abs(dist_to_edge) <= abs(move_y):
            white_ball.y += dist_to_edge
            move_y -= dist_to_edge
            move_y *= -1
    else:
        if move_x > 0:
            dist_to_edge = RIGHT - RADIUS - white_ball.x
        else:
            dist_to_edge = LEFT + RADIUS - white_ball.x
        if abs(dist_to_edge) <= abs(move_x):
            white_ball.x += dist_to_edge
            move_x -= dist_to_edge
            move_x *= -1
    return white_ball, move_x, move_y

hit_ball = find_first_hit(balls, white_ball, move_x, move_y)
if hit_ball is None:
    white_ball, move_x, move_y = collide(white_ball, move_x, move_y)
    hit_ball = find_first_hit(balls, white_ball, move_x, move_y)

if hit_ball is None:
    print("MISS")
elif hit_ball.color != on_color:
    print("FOUL")
else:
    print("HIT")

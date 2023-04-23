#!/usr/bin/python3
import math

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

filtered_balls = []
func = min
keyfunc = None

def get_keyfunc(distance, axis, other_axis):
    def f(val):
        other_axis_diff = abs(val.__getattribute__(other_axis) - white_ball.__getattribute__(other_axis))
        return other_axis_diff
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

if keyfunc(hit_ball) > abs(move_x or move_y):
    hit_ball = None

if hit_ball is None:
    print("MISS")
elif hit_ball.color != on_color:
    print("FOUL")
else:
    print("HIT")

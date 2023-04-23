#!/usr/bin/python3
import math

# read input
n = int(input())
balls = []
for i in range(n):
    color, x, y = input().split()
    x, y = float(x), float(y)
    balls.append((color, x, y))
on_color = input().strip()
vx, vy = map(float, input().split())

# find the on color ball
on_ball = None
for ball in balls:
    if ball[0] == on_color:
        on_ball = ball
        break

# simulate the movement of the white ball
x, y = 0, 0
r = 1
dt = 0.01
while True:
    # calculate the new position of the white ball
    x += vx * dt
    y += vy * dt

    # check if the white ball hits any of the other balls
    for ball in balls:
        if ball[0] == "white":
            continue
        dx = x - ball[1]
        dy = y - ball[2]
        dist = math.sqrt(dx**2 + dy**2)
        if dist <= r + 1:
            # the white ball collided with a ball
            if ball[0] == on_color:
                print("HIT")
            else:
                print("FOUL")
            exit()

    # check if the white ball hits a side of the table
    if x < r or x > 70 - r:
        vx = -vx
    if y < r or y > 140.5 - r:
        vy = -vy

    # check if the white ball has stopped moving
    if abs(vx) < 0.1 and abs(vy) < 0.1:
        print("MISS")
        exit()


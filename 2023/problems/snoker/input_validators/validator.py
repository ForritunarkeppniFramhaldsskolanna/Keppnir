#!/usr/bin/python3
import sys
import re

from collections import Counter

LEGAL_COLORS = ['white', 'red', 'yellow', 'green', 'brown', 'blue', 'pink', 'black']
RADIUS = 1
EPS = 1e-4

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 2 <= n <= 22

balls = []

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[a-z]* -?[0-9]*[.][0-9]{3} -?[0-9]*[.][0-9]{3}\n$', line)
    color, x, y = line.split()
    x = float(x)
    y = float(y)
    assert color in LEGAL_COLORS
    assert 1 <= x <= 69
    assert 1 <= y <= 139.5
    balls.append((color, x, y))

line = sys.stdin.readline()
assert re.match('^[a-z]*\n$', line)
on_color = line.strip()
assert on_color in LEGAL_COLORS and on_color != "white"

line = sys.stdin.readline()
assert re.match('^-?[0-9]*[.][0-9]{3} -?[0-9]*[.][0-9]{3}\n$', line)
vx, vy = map(float, line.split())


color_counts = Counter(color for color, x, y in balls)
assert color_counts['white'] == 1
assert 0 <= color_counts['red'] <= 15
for color in LEGAL_COLORS:
    if color not in ['white', 'red']:
        assert 0 <= color_counts[color] <= 1

for i, ball in enumerate(balls):
    for j, other in enumerate(balls[i+1:]):
        required_distance = 2*RADIUS+EPS if ball[0] == "white" or other[1] == "white" else 2*RADIUS
        dx = ball[1]-other[1]
        dy = ball[2]-other[2]
        assert dx**2 + dy**2 >= required_distance**2

assert not sys.stdin.read()
sys.exit(42)

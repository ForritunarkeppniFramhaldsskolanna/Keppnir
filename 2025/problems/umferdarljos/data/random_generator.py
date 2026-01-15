#!/usr/bin/python3
import sys
import random

from point import Point
from segment import Segment
from fractions import Fraction

random.seed(int(sys.argv[-1]))

MIN_COORD = -1000000
MAX_COORD = 1000000

MAX_INTERSECTIONS = 100000
SCALE_EXPONENT = 3

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

number_of_segments = random.randint(min_n, max_n)

segments = []
intersection_points = set()

min_scale = 0.0
max_scale = 0.9

while len(segments) < number_of_segments:
    x1 = Fraction(random.randint(MIN_COORD, MAX_COORD), 1)
    y1 = Fraction(random.randint(MIN_COORD, MAX_COORD), 1)
    x2 = Fraction(random.randint(MIN_COORD, MAX_COORD), 1)
    y2 = Fraction(random.randint(MIN_COORD, MAX_COORD), 1)
    dx = x2 - x1
    dy = y2 - y1
    scaling = random.uniform(min_scale, max_scale) ** SCALE_EXPONENT
    x2 = x1 + Fraction(int(round(dx * scaling)), 1)
    y2 = y1 + Fraction(int(round(dy * scaling)), 1)
    if x1 == x2 and y1 == y2:
        continue
    s = Segment(Point(x1, y1), Point(x2, y2))
    temp_inter = []
    success = True
    for other in segments:
        inter = s.intersect(other)
        if inter is None:
            continue
        if isinstance(inter, Segment):
            success = False
            break
        if inter in intersection_points:
            success = False
            break
        temp_inter.append(inter)
        if len(temp_inter) > MAX_INTERSECTIONS - len(intersection_points):
            success = False
            break
    if not success:
        continue
    segments.append(s)
    for inter in temp_inter:
        if isinstance(inter, Segment):
            assert False
        intersection_points.add(inter)

print(number_of_segments)
for (x1, y1), (x2, y2) in segments:
    print(x1, y1, x2, y2)

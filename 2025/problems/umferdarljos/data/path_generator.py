#!/usr/bin/python3
import sys
import random

from point import Point
from segment import Segment

random.seed(int(sys.argv[-1]))

MIN_COORD = -1000000
MAX_COORD = 1000000

MAX_INTERSECTIONS = 100000

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
min_parts = int(sys.argv[3])
max_parts = int(sys.argv[4])
is_horizontal = sys.argv[5] == "horizontal"

number_of_parts = random.randint(min_parts, max_parts)

segments = []
intersection_points = set()

xs = sorted(random.sample(range(MIN_COORD, MAX_COORD + 1), number_of_parts))
segments = []

for i in range(number_of_parts):
    seg_in_part = random.randint(min_n // number_of_parts, max_n // number_of_parts)
    ys = sorted(random.sample(range(MIN_COORD, MAX_COORD + 1), 2 * seg_in_part))
    for j in range(0, len(ys), 2):
        if j >= 2 and random.choice([True, False]):
            ys[j] = ys[j - 1]
        if random.choice([True, False]):
            segments.append(Segment(Point(xs[i], ys[j]), Point(xs[i], ys[j + 1])))
        else:
            segments.append(Segment(Point(xs[i], ys[j + 1]), Point(xs[i], ys[j])))

random.shuffle(segments)
print(len(segments))
for (x1, y1), (x2, y2) in segments:
    if is_horizontal:
        x1, y1, x2, y2 = y1, x1, y2, x2
    print(x1, y1, x2, y2)

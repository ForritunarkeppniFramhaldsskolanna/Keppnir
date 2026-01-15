#!/usr/bin/python3
import sys
import random

from collections import defaultdict
from fractions import Fraction
from point import Point
from segment import Segment

random.seed(int(sys.argv[-1]))

MIN_COORD = -1000000
MAX_COORD = 1000000

MAX_INTERSECTIONS = 100000
SCALE_EXPONENT = 3

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
allow_non_endpoint_intersections = sys.argv[3] == "any"

min_x, max_x, min_y, max_y = MIN_COORD, MAX_COORD, MIN_COORD, MAX_COORD

min_scale = 0.0
max_scale = 0.9

number_of_segments = random.randint(min_n, max_n)

horizontal_mapping = defaultdict(list)
vertical_mapping = defaultdict(list)


def has_bad_intersection(inter, seg_a, seg_b):
    if inter is None:
        return False
    if isinstance(inter, Segment):
        return True
    if inter in intersection_points:
        return True
    if allow_non_endpoint_intersections:
        return False
    return not (inter in [seg_a.p, seg_a.q] and inter in [seg_b.p, seg_b.q])


segments = []
intersection_points = set()
count = defaultdict(int)


def _generate_vertical_segment(min_x, max_x, min_y, max_y):
    while True:
        if len(segments) == 0 or random.choices([True, False], weights=[0.3, 0.7])[0]:
            x = Fraction(random.randint(min_x, max_x), 1)
            y1 = Fraction(random.randint(min_y, max_y), 1)
            y2 = Fraction(random.randint(min_y, max_y), 1)
        else:
            seg = random.choice(segments)
            point = random.choice(list(seg))
            x = point.x
            y1 = point.y
            y2 = Fraction(random.randint(min_y, max_y), 1)
        dy = y2 - y1
        scaling = random.uniform(min_scale, max_scale) ** SCALE_EXPONENT
        y2 = y1 + Fraction(int(round(dy * scaling)), 1)
        p, q = Point(x, y1), Point(x, y2)
        if p != q and count[p] < 2 and count[q] < 2:
            break
    return Segment(p, q)


def _generate_horizontal_segment(min_x, max_x, min_y, max_y):
    while True:
        if len(segments) == 0 or random.choices([True, False], weights=[0.3, 0.7])[0]:
            y = Fraction(random.randint(min_y, max_y), 1)
            x1 = Fraction(random.randint(min_x, max_x), 1)
            x2 = Fraction(random.randint(min_x, max_x), 1)
        else:
            seg = random.choice(segments)
            point = random.choice(list(seg))
            y = point.y
            x1 = point.x
            x2 = Fraction(random.randint(min_x, max_x), 1)
        dx = x2 - x1
        scaling = random.uniform(min_scale, max_scale) ** SCALE_EXPONENT
        x2 = x1 + Fraction(int(round(dx * scaling)), 1)
        p, q = Point(x1, y), Point(x2, y)
        if p != q and count[p] < 2 and count[q] < 2:
            break
    return Segment(p, q)


def generate_vertical_segment(min_x, max_x, min_y, max_y):
    seg = _generate_vertical_segment(min_x, max_x, min_y, max_y)
    temp_inter = [(seg.intersect(other), seg, other) for other in segments]
    temp_inter = [tup for tup in temp_inter if tup[0] is not None]
    while (
        any(has_bad_intersection(ip, seg_a, seg_b) for (ip, seg_a, seg_b) in temp_inter)
        or len(intersection_points) + len(temp_inter) > MAX_INTERSECTIONS
    ):
        seg = _generate_vertical_segment(min_x, max_x, min_y, max_y)
        temp_inter = [(seg.intersect(other), seg, other) for other in segments]
    vertical_mapping[seg.p.x].append(seg)
    return seg, temp_inter


def generate_horizontal_segment(min_x, max_x, min_y, max_y):
    seg = _generate_horizontal_segment(min_x, max_x, min_y, max_y)
    temp_inter = [(seg.intersect(other), seg, other) for other in segments]
    temp_inter = [tup for tup in temp_inter if tup[0] is not None]
    while (
        any(has_bad_intersection(ip, seg_a, seg_b) for (ip, seg_a, seg_b) in temp_inter)
        or len(intersection_points) + len(temp_inter) > MAX_INTERSECTIONS
    ):
        seg = _generate_horizontal_segment(min_x, max_x, min_y, max_y)
        temp_inter = [(seg.intersect(other), seg, other) for other in segments]
    horizontal_mapping[seg.p.y].append(seg)
    return seg, temp_inter


def generate_segment(min_x, max_x, min_y, max_y):
    if random.choice([True, False]):
        seg, temp_inter = generate_vertical_segment(min_x, max_x, min_y, max_y)
    else:
        seg, temp_inter = generate_horizontal_segment(min_x, max_x, min_y, max_y)
    count[seg.p] += 1
    count[seg.q] += 1
    for inter, _seg_a, _seg_b in temp_inter:
        if inter is None:
            continue
        elif isinstance(inter, Segment):
            assert False, f"{temp_inter}"
        else:
            intersection_points.add(inter)
    return seg


while len(segments) < number_of_segments:
    segments.append(generate_segment(min_x, max_x, min_y, max_y))

print(number_of_segments)
for segment in segments:
    p, q = segment
    print(*p, *q)
    # print(f"Segment(({p.x},{p.y}),({q.x},{q.y}))")

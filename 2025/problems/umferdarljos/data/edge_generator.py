#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

LIM = 10**6

if typ == "double_stress":
    print(2)
    print(LIM, LIM, LIM - 1, -LIM)
    print(LIM - 1, -LIM + 1, -LIM, LIM)
elif typ == "double_stress_2":
    print(2)
    print(0, -LIM, LIM, LIM)
    print(-LIM, LIM, LIM // 2, 0)
elif typ == "horizontal":
    print(2)
    print(0, 0, 1, 0)
    print(0, 0, -1, 0)
elif typ == "vertical":
    print(2)
    print(1, 0, 0, 0)
    print(-1, 0, 0, 0)
elif typ == "NE":
    print(2)
    print(-LIM, LIM, LIM, LIM)
    print(LIM, -LIM, LIM, LIM)
elif typ == "NW":
    print(2)
    print(-LIM, LIM, LIM, LIM)
    print(-LIM, -LIM, -LIM, LIM)
elif typ == "SW":
    print(2)
    print(-LIM, -LIM, LIM, -LIM)
    print(LIM, -LIM, LIM, LIM)
elif typ == "SE":
    print(2)
    print(-LIM, -LIM, LIM, -LIM)
    print(-LIM, -LIM, -LIM, LIM)
elif typ == "bounding_box":
    print(4)
    print(-LIM, -LIM, -LIM, LIM)
    print(-LIM, LIM, LIM, LIM)
    print(LIM, LIM, LIM, -LIM)
    print(LIM, -LIM, -LIM, -LIM)
else:
    assert False, f"Invalid edge case type: {typ}"

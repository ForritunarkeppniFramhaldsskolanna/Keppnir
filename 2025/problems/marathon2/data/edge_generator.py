#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

END = 42195

n = int(sys.argv[1])
x = int(sys.argv[2])
y = int(sys.argv[3])
h = int(sys.argv[4])
s = int(sys.argv[5])
offset = int(sys.argv[6])

sys.stdout.write(f"{n} {x} {y}\n")
sys.stdout.write(f"{h} {s}\n")

last = 0
for i in range(n):
    station = last + x + offset
    # Already reached end so lets start another chain from
    # a random location
    if station > END:
        station = random.randint(0, END)
    last = station
    sys.stdout.write(f"{station}\n")

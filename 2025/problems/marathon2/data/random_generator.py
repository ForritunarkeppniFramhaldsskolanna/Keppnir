#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

END = 42195

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
min_x = int(sys.argv[3])
max_x = int(sys.argv[4])
h_equals_s = int(sys.argv[5])

n = random.randint(min_n, max_n)
x = random.randint(min_x, max_x)
y = random.randint(0, 100)

h = random.randint(1, 10)
s = 0
if h_equals_s:
    s = h
else:
    # To make sure we don't have h = s unless we force it
    if h == 1:
        h += 1
    s = random.randint(1, h - 1)

sys.stdout.write(f"{n} {x} {y}\n")
sys.stdout.write(f"{h} {s}\n")

for i in range(n):
    station = random.randint(1, END)
    sys.stdout.write(f"{station}\n")

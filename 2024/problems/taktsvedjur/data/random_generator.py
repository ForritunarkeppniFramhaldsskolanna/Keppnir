#!/usr/bin/python3
import sys, random, math

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
min_note = eval(sys.argv[2])
max_note = eval(sys.argv[3])

n = random.choice([random.randint(max_n // 2, max_n), max_n])
cons = True

if max_note == 0:
    n = 10 * int(sys.argv[4])
elif len(sys.argv) >= 5 and int(sys.argv[4]) == -1:
    cons = False

print(n)

lst = 0
for _ in range(n):
    if not cons and lst != 0:
        print(0)
        lst = 0
        continue
    if min_note == 0 and random.randint(1, 8) == 1:
        print(0)
        lst = 0
    else:
        print(random.randint(min_note, max_note))
        lst = 1

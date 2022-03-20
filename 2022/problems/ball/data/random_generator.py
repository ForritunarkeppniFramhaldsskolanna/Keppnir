#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
cut_position = sys.argv[3]

n = 1
while n % 2 == 1:
    n = random.randint(min_n, max_n)
L = list(range(1, n+1))
random.shuffle(L)
if cut_position == "start":
    cut = 0
elif cut_position == "end":
    cut = n//2
else:
    cut = random.randint(0, n//2)
pairs = []
for i in range(cut):
    pairs.append((L[2*i], L[2*i+1]))

a = random.randint(1, n)
b = a
while b == a:
    b = random.randint(1, n)
pairs.append((a, b))

for i in range(cut, n//2):
    pairs.append((L[2*i], L[2*i+1]))



sys.stdout.write("{}\n".format(n))
for a,b in pairs:
    sys.stdout.write("{} {}\n".format(a, b))

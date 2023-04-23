#!/usr/bin/python3
import sys
K = int(input())
a = int(input())
b = int(input())
sols = []
i = 0
while i*a <= K:
    remainder = K - i*a
    if remainder % b == 0:
        j = remainder // b
        sols.append((i,j))
    i += 1
sys.stdout.write("{}\n".format(len(sols)))
for kill, assist in sols:
    sys.stdout.write("{} {}\n".format(kill, assist))
sys.stdout.flush()

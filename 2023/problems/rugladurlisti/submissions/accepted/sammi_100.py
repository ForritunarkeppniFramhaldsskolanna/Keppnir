#!/usr/bin/python3
import sys

n = int(sys.stdin.readline())

ans = [0 for _ in range(n)]

ask = [[] for _ in range(30)]

def rec(i, l, h):
    if h - l <= 1:
        return

    global ask

    m = (l + h + 1)//2
    for j in range(l, m):
        ask[i].append(str(j + 1))

    rec(i+1, l, m)
    rec(i+1, m, h)

rec(0, 0, n)

i = 0
while ask[i]:
    sys.stdout.write(f"? {len(ask[i])} " + " ".join(ask[i]))
    sys.stdout.write("\n")
    sys.stdout.flush()

    inp = list(map(int, sys.stdin.readline().strip().split()))

    for j in range(n):
        ans[j] <<= 1
    
    for j in inp:
        ans[j-1] += 1

    i += 1

to_print = []

for k in range(n):
    to_print.append((ans[k], str(k+1)))

sys.stdout.write("!")

for val, num in sorted(to_print, reverse=True):
    sys.stdout.write(" " + num)

sys.stdout.write("\n")

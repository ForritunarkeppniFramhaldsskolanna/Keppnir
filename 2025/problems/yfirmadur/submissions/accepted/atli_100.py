#!/usr/bin/python3

import heapq
import sys

avail = []


def get_new_num():
    global avail
    x = heapq.heappop(avail)
    if len(avail) == 0:
        avail = [x + 1]
    return x


n, q = map(int, sys.stdin.readline().strip().split())
avail.append(n)
working = [True for _ in range(n)]
parent = [int(x) - 1 for x in sys.stdin.readline().strip().split()]
index = list(range(n))
number = list(range(n))
for _ in range(q):
    op, x = sys.stdin.readline().strip().split()
    x = int(x) - 1
    if op == "+":
        y = get_new_num()
        if y >= len(index):
            index.append(len(working))
        else:
            index[y] = len(working)
        working.append(True)
        parent.append(index[x])
        number.append(y)
    elif op == "-":
        heapq.heappush(avail, x)
        working[index[x]] = False
    else:
        x = index[x]
        ans = parent[x]
        while not working[ans]:
            ans = parent[ans]
        fix = parent[x]
        parent[x] = ans
        while not working[fix]:
            tmp = parent[fix]
            parent[fix] = ans
            fix = tmp
        sys.stdout.write(str(number[ans] + 1) + "\n")

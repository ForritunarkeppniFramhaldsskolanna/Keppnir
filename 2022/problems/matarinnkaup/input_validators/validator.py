#!/usr/bin/python3
import sys

u, k = map(int, input().strip().split())
dsh = set()

for i in range(u):
    nm = input().strip()
    assert nm not in dsh
    dsh.add(nm)
    h = int(input())
    ings = set()
    for j in range(h):
       ing,cnt = input().split()
       assert ing not in ings
       ings.add(ing)

for i in range(k):
    n = int(input())
    for j in range(n):
        s, x = input().strip().split()
        assert s in dsh

sys.exit(42)

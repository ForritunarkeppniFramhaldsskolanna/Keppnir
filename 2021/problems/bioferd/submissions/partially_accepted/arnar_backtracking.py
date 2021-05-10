#!/bin/python3
import sys
n = int(input())
k = [0]*n
x = [0]*n
for i in range(n):
    line = input()
    k[i],*x[i] = map(int, line.split())
    for j in range(k[i]):
        x[i][j] -= 1

seat = [0 for i in range(n)]
def rec(at):
    if at == n:
        print(' '.join(str(a) for a in seat))
        sys.exit()
    for val in x[at]:
        if seat[val] == 0:
            seat[val] = at+1
            rec(at+1)
            seat[val] = 0

rec(0)

print("Neibb")

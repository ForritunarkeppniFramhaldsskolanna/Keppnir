#!/usr/bin/python3
import sys
n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

ans = 2022

for i in range(n//k):
	ans += 1

print(ans)
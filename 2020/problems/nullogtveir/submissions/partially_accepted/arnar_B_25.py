#!/usr/bin/python3

n = int(input())

cnt = 0
for i in range(0,n+1):
    s = str(i)
    if not any(x not in '20' for x in s):
        cnt += 1

print(cnt)

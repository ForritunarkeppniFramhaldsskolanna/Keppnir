#!/usr/bin/python3
n, m = map(int, input().split())
if n == 2 and m == 1:
    helsinki, buenos = map(int, input().split())
    _, _, a, b = map(int, input().split())
    print(min(helsinki+b, buenos+a))
else:
    print(min(map(int, input().split())))

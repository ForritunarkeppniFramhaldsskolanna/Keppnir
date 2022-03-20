#!/usr/bin/python3
n, m = map(int, input().split())
helsinki, buenos = map(int, input().split())
_, _, a, b = map(int, input().split())
print(min(helsinki+b, buenos+a))

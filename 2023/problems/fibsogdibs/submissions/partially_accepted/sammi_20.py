#!/usr/bin/python3

def rec(n):
    if n == 0:
        return a
    if n == 1:
        return b
    
    return rec(n - 1) + rec(n - 2)

a, b = map(int, input().split())
n = int(input())

print(rec(2*n) % (10**9 + 7), rec(2*n+1) % (10**9 + 7))

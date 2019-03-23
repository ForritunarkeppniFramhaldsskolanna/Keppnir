#!/usr/bin/python3
# @EXPECTED_SCORE@: 100
n, m, k = map(int, input().split())
S = list(map(int, input().split()))
if m > k:
    print(":(")
else:
    sm = sum(S)
    a = k//m
    print(sm//a)

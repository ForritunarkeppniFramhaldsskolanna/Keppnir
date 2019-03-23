#!/usr/bin/python3
# @EXPECTED_SCORE@: 50
n, m, k = map(int, input().split())
S = list(map(int, input().split()))
if m > k:
    print(":(")
else:
    at = 0
    mins = 0
    d = 0
    while at < n:
        if S[at] == 0:
            at += 1
        elif mins < m:
            d+=1
            mins = k
        else:
            mins -= m
            S[at] -= 1
    print(d)

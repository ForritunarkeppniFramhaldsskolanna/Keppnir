#!/usr/bin/python2
import sys
n, m, k = map(int, sys.stdin.readline().split())
S = list(map(int, sys.stdin.readline().split()))
if m > k:
    print(":(")
else:
    sm = sum(S)
    a = k//m
    print((sm+a-1)//a)

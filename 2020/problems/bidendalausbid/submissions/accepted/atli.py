#!/usr/env/bin python3
t1 = input()
t2 = input()

h1, s1 = [int(x) for x in t1.strip().split(':')]
h2, s2 = [int(x) for x in t2.strip().split(':')]

v1 = h1 * 60 + s1
v2 = h2 * 60 + s2

if v2 < v1:
    v2 += 60 * 24

print(v2 - v1)

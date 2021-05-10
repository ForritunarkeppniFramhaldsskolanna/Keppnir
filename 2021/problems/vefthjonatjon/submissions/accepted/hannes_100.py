#!/usr/bin/env python3

n = int(input())

cpus = 0
mem = 0
hdd = 0

for i in range(n):
    c, m, h = map(lambda x: x == "J", input().split(" "))
    cpus += c
    mem += m
    hdd += h

print(min(cpus, mem, hdd))
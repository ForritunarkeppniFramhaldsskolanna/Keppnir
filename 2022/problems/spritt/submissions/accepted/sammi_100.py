#!/usr/bin/python3
import sys

n, x = map(int, sys.stdin.readline().split())

arr = []

for _ in range(n):
	arr.append(int(sys.stdin.readline()))

if x >= sum(arr):
	print("Jebb")
else:
	print("Neibb")
#!/usr/bin/python3
m = int(input())
n = int(input())

empty = 0
for i in range(n):
    line = input()
    empty += line.count(".")

print(f"{empty/(m*n):.2f}")
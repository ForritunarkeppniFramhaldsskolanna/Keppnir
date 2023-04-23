#!/usr/bin/python3
m = int(input())
n = int(input())

total_cells = m * n
empty_cells = 0

for i in range(n):
    row = input().strip()
    empty_cells += row.count('.')

proportion = empty_cells / total_cells
print("{:.6f}".format(proportion))


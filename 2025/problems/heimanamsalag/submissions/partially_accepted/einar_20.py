from math import ceil

n = int(input())
a, b, c = map(int, input().split())

print(ceil(c / ((b + 1) - (a))))

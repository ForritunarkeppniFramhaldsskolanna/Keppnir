#!python3
n, k = [int(x) for x in input().strip().split()]

sm = 0
md = 10 ** 9 + 7

for i in range(1, n + 1):
    sm += pow(i, k, md)
    sm %= md

print(sm)


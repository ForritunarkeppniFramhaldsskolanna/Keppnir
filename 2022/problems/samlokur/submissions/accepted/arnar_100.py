#!/usr/bin/python3
n, k = map(int, input().split())
S = sorted(zip(map(int, input().split()),
               map(int, input().split())),
           key=lambda x: x[1])

low = list(filter(lambda x: x[0] == 4, S))
high = list(filter(lambda x: x[0] > 4, S))


def die():
    print("Neibb")
    exit()

for i in range(k, 0, -1):
    if len(high) == 0:
        die()
    if high[-1][1] < i:
        die()
    high.pop()
    if len(low) > 0 and low[-1][1] >= i:
        low.pop()
    elif len(high) > 0 and high[-1][1] >= i:
        high.pop()
    else:
        die()

print("Jebb")

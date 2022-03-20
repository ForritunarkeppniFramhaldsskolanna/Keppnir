#!/usr/bin/python3
n, k = map(int, input().split())
a = map(int, input().split())
b = map(int, input().split())

sandwiches = sorted(zip(a, b), key=lambda x: x[1])

def die():
    print("Neibb")
    exit()

for i in range(k, 0, -1):
    high = 0
    low = 0
    index = len(sandwiches)-1
    while high + low < 2:
        print(sandwiches)
        print(i, index, low, high)
        if index < 0:
            die()
        s = sandwiches[index]
        if s[1] < i:
            die()
        if s[0] > 4:
            high += 1
            sandwiches.pop(index)
            index = len(sandwiches)-1
            continue
        elif s[0] == 4 and low == 0:
            low += 1
            sandwiches.pop(index)
            index = len(sandwiches)-1
            continue
        index -= 1

print("Jebb")

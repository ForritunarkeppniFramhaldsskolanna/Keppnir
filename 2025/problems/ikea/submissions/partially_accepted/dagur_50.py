#!/usr/bin/python3
k = int(input())
n = int(input())
names = [input().split(" ") for _ in range(n)]
names.sort(key=lambda x: int(x[1]))

amt = n // k
total = 0
chosen = [""] * amt
for enum, elem in enumerate(names[:amt]):
    total += int(elem[1])
    chosen[enum] = elem[0]

print(total)
chosen.sort()
for elem in chosen:
    print(elem)

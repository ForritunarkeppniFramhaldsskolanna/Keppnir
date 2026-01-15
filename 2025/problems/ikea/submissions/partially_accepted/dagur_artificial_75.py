#!/usr/bin/python3

k = int(input())
n = int(input())
names = [input().split(" ") for _ in range(n)]
names.sort(key=lambda x: int(x[1]))

amt = n // k

if n <= 10:
    if n % k != 0:
        badPersonSum = sum(int(x[1]) for x in names[: amt + 1])
        nextSum = sum(int(x[1]) for x in names[amt + 1 : 2 * amt + 1])
        if badPersonSum < nextSum:
            amt += 1
    total = 0
    chosen = [""] * amt
    for enum, elem in enumerate(names[:amt]):
        total += int(elem[1])
        chosen[enum] = elem[0]

    print(total)
    chosen.sort()
    for elem in chosen:
        print(elem)
    exit()


total = 0
chosen = [""] * amt
for enum, elem in enumerate(names[:amt]):
    total += int(elem[1])
    chosen[enum] = elem[0]

print(total)
chosen.sort()
for elem in chosen:
    print(elem)

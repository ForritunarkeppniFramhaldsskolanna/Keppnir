#!/usr/bin/python3
n = int(input())

count = [0] * 10
for i in range(1, n+1):
    if i % 10 == 7:
        count[7] += 1
    elif i % 10 == 4:
        count[4] += 1
    elif i % 10 == 1:
        count[1] += 1

result = 0
for i in range(10):
    for j in range(10):
        for k in range(10):
            if (i + 4*j + k) % 10 == 7:
                result += count[i] * count[j] * count[k]

print(result)

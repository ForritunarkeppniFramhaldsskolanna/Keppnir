#!/usr/bin/python3
n, m = map(int, input().split())
for i in range(n + 1):
    for j in range(i, n + 1):
        k = n - j - i
        if k < j:
            break
        if i + 1 + j + 1 > m:
            print("Arnar")
            exit(0)
print("Unnar")

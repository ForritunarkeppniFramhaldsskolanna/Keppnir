#!/usr/bin/python3
import sys

n = int(sys.stdin.readline())

s = set(str(i + 1) for i in range(n))

ans = []

for i in range(n-1):
    sys.stdout.write(f"? 1 {i + 1}\n")
    sys.stdout.flush()

    ans.append(input().strip())

for j in s.symmetric_difference(set(ans)):
    ans.append(j)

print("! " + " ".join(ans))
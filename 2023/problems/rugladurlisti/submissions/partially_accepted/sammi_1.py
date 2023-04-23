#!/usr/bin/python3
import sys

n = int(sys.stdin.readline())

ans = []

for i in range(n):
    sys.stdout.write(f"? 1 {i + 1}\n")
    sys.stdout.flush()

    ans.append(input())

print("! " + " ".join(ans))
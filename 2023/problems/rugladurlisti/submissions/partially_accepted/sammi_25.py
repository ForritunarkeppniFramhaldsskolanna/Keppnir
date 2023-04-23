#!/usr/bin/python3
import sys

n = int(sys.stdin.readline())

ans = []

for i in range(0, n-2, 3):
    sys.stdout.write(f"? 2 {i+1} {i+2}\n")
    sys.stdout.flush()
    a, b = map(str, input().strip().split())

    sys.stdout.write(f"? 2 {i+2} {i+3}\n")
    sys.stdout.flush()
    c, d = map(str, input().strip().split())

    if c == a:
        ans.append(b)
        ans.append(c)
        ans.append(d)
    elif c == b:
        ans.append(a)
        ans.append(c)
        ans.append(d)
    elif d == a:
        ans.append(b)
        ans.append(d)
        ans.append(c)
    else:
        ans.append(a)
        ans.append(d)
        ans.append(c)

for j in range(n % 3, 0, -1):
    sys.stdout.write(f"? 1 {n - j + 1}\n")
    ans.append(input().strip())

print("! " + " ".join(ans))
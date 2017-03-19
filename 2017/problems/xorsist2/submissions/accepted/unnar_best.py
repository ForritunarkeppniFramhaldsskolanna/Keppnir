#!/usr/bin/env python3

n = int(input())
a, b = map(int, input().split())
f = lambda x: (x, 1, x+1, 0)[x%4]
res = f(a-1)^f(b)
print(res if 1 <= res <= n else "Enginn" if res == 0 else "Gunnar")

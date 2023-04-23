#!/usr/bin/python3
# This took a bit of guidance/pointing out errors on samples
def fibs_and_dibs(a, b, n):
    mod = int(1e9 + 7)
    for i in range(n):
        c = a + b
        a, b = b, c
        c = a + b
        a, b = b, c
    return a, b

a, b = map(int, input().split())
n = int(input().strip())

res = fibs_and_dibs(a, b, n)
print((res[0] % (10**9 + 7)), (res[1] % (10**9 + 7)))


#!/usr/bin/python3
import sys
n,m = map(int, input().split())
A = ['?']*n
for i in range(m):
    k, s = input().split()
    k = int(k)
    for j in range(len(s)):
        if A[k-1+j] == '?' or A[k-1+j] == s[j]:
            A[k-1+j] = s[j]
        else:
            print("Villa")
            sys.exit()

print(''.join(A))

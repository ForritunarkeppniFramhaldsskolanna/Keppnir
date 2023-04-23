#!/usr/bin/python3
K = int(input())
a = int(input())
b = int(input())
sols = set()
i = 0
while i*a <= K:
    lo = 0
    hi = 10**9
    # binary search
    while lo <= hi:
        j = (lo+hi)//2
        expr = i*a + j*b
        if expr < K:
            lo = j+1
        elif expr > K:
            hi = j-1
        else:
            sols.add((i,j))
            break
        #print(f"lo: {lo}, hi: {hi}")
    i += 1
print(len(sols))
for kill, assist in sols:
    print(kill, assist)

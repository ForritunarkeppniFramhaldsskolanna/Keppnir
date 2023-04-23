#!/usr/bin/python3
K = int(input())
a = int(input())
b = int(input())
sols = set()
i = 0
while i*a <= K:
    j = 0
    while i*a + j*b <= K:
        if i*a + j*b == K:
            sols.add((i,j))
        j += 1
    i += 1
print(len(sols))
for kill, assist in sols:
    print(kill, assist)

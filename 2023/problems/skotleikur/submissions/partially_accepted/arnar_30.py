#!/usr/bin/python3
K = int(input())

sols = []
for i in range(11):
    remaining = K - 100*i
    if remaining >= 0 and remaining % 50 == 0:
        sols.append((i, remaining // 50))

print(len(sols))
for sol in sols:
    print(*sol)

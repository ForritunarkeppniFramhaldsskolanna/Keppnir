#!/usr/bin/python3
COST = {'.': 20, 'O': 10, '\\': 25, '/': 25, 'A': 35, '^': 5, 'v': 22}
n, m = map(int, input().split())
if max(n, m) > 50:
    print(n*m*COST['.'])
else:
    text = ''.join([input() for i in range(n)])
    result = 0
    for key, value in COST.items():
        s = ""
        for c in text:
            if c == key:
                s += c
        result += len(s)*value
    print(result)

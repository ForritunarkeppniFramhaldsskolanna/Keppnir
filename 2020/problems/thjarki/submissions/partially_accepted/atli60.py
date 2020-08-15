#!/usr/env/bin python3
n, m = [int(x) for x in input().strip().split()]
mp = [list(input().strip()) for i in range(n)]

def mov(p):
    if mp[p[0]][p[1]] == '^':
        return (p[0] - 1, p[1])
    if mp[p[0]][p[1]] == '<':
        return (p[0], p[1] - 1)
    if mp[p[0]][p[1]] == '>':
        return (p[0], p[1] + 1)
    if mp[p[0]][p[1]] == 'v':
        return (p[0] + 1, p[1])
    assert False

q = int(input())
for _ in range(q):
    a, b, k = [int(x) for x in input().strip().split()]
    pos = (a - 1, b - 1)
    if k > 1000:
        been = set()
        been.add(pos)
        while k > 0:
            pos = mov(pos)
            k -= 1
            if pos in been:
                break
            been.add(pos)
        if k % 2 == 1:
            pos = mov(pos)
    else:
        for _ in range(k):
            pos = mov(pos)
    print(pos[0] + 1, pos[1] + 1)


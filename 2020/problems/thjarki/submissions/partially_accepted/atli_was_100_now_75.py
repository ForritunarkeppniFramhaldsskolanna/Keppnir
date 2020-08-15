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

def floyd(p0):
    t, h, mu, lam = mov(p0), mov(mov(p0)), 0, 1
    while t != h:
        t = mov(t)
        h = mov(mov(h))
    h = p0
    while t != h:
        t = mov(t)
        h = mov(h)
        mu += 1
    h = mov(t)
    while t != h:
        h = mov(h)
        lam += 1
    return (mu, lam)

q = int(input())

for _ in range(q):
    a, b, k = [int(x) for x in input().strip().split()]
    mu, lam = floyd((a - 1, b - 1))
    pos = (a - 1, b - 1)
    while k > 0 and mu > 0:
        pos = mov(pos)
        k -= 1
        mu -= 1
    k %= lam
    while k > 0:
        pos = mov(pos)
        k -= 1

    print(pos[0] + 1, pos[1] + 1)
    


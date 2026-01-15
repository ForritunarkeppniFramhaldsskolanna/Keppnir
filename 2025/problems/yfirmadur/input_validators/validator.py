#!/usr/bin/python3

import re
import sys
import heapq


class UnionFind:
    def __init__(self, n):
        self.p = [-1 for i in range(n)]

    def find(self, x):
        while self.p[x] >= 0:
            x, self.p[x] = self.p[x], self.p[self.p[x]]
        return x

    def united(self, x, y):
        return self.find(x) == self.find(y)

    def unite(self, x, y):
        xp = self.find(x)
        yp = self.find(y)
        if xp == yp:
            return
        if self.p[xp] > self.p[yp]:
            xp, yp = yp, xp
        self.p[xp] += self.p[yp]
        self.p[yp] = xp

    def size(self, x):
        return -self.p[self.find(x)]


max_n = 2 * 10**5
max_q = 2 * 10**5
allow_add = True
allow_rem = True

exec(sys.argv[1])  # max_n
exec(sys.argv[2])  # max_q
exec(sys.argv[3])  # allow_add
exec(sys.argv[4])  # allow_rem

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)
n, q = map(int, line.strip().split())
assert 1 <= n <= max_n
assert 1 <= q <= max_q

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*( [1-9][0-9]*)*\n$", line)
par = list(map(int, line.strip().split()))
assert len(par) == n
for x in par:
    assert 1 <= x <= n
assert par[0] == 1

uf = UnionFind(n)
for i in range(1, n):
    assert not uf.united(i, par[i] - 1)
    uf.unite(i, par[i] - 1)
assert uf.size(0) == n

avail_nums = [n + 1]
used_nums = set()
for i in range(n):
    used_nums.add(i + 1)

for _ in range(q):
    line = sys.stdin.readline()
    assert re.match("^[+\-?] [1-9][0-9]*\n$", line)
    op, x = line.strip().split()
    x = int(x)
    assert x in used_nums
    if op == "+":
        y = heapq.heappop(avail_nums)
        if len(avail_nums) == 0:
            avail_nums = [y + 1]
        used_nums.add(y)
        assert allow_add
    if op == "-":
        used_nums.remove(x)
        heapq.heappush(avail_nums, x)
        assert allow_rem

assert not sys.stdin.read()
sys.exit(42)

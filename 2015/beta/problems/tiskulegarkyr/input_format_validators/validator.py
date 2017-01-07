import sys
import re

sys.setrecursionlimit(1000000)

sz = sys.stdin.readline()
assert re.match('^[?0-9]+ [0-9]+\n$', sz)
n, m = map(int, sz.strip().split())
assert 1 <= n <= 50
assert 1 <= m <= 50

spot = [ [False for j in range(m) ] for i in range(n) ]
comp = [ [-1 for j in range(m) ] for i in range(n) ]

for i in range(n):
    line = sys.stdin.readline()
    assert len(line) == m + 1
    assert line[-1] == '\n'
    line = line[:-1]

    for j in range(m):
        assert line[j] in {'.', 'X'}
        if line[j] == 'X':
            spot[i][j] = True

def dfs(i, j, comps):
    if i < 0 or j < 0 or i >= n or j >= m:
        return
    if not spot[i][j]:
        return
    if comp[i][j] != -1:
        return

    comp[i][j] = comps
    dfs(i-1,j,comps)
    dfs(i+1,j,comps)
    dfs(i,j-1,comps)
    dfs(i,j+1,comps)

comps = 0
for i in range(n):
    for j in range(m):
        if spot[i][j] and comp[i][j] == -1:
            dfs(i, j, comps)
            comps += 1

assert comps == 2
assert sys.stdin.read() == ''

sys.exit(42)

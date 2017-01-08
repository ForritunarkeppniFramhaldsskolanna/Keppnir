import sys

class Trie:
    def __init__(self):
        self.down = {}
        self.cnt = 0

root = Trie()
n = int(sys.stdin.readline().strip())
sm = 0
for i in range(n):
    op,n = sys.stdin.readline().strip().split()
    n = int(n)
    cur = root

    if op == 'A':
        dx = 1
    else:
        dx = -1

    sm += dx * n

    for i in range(29,-1,-1):
        cur.cnt += dx
        b = (n>>i)&1
        if b not in cur.down:
            cur.down[b] = Trie()
        cur = cur.down[b]
    cur.cnt += dx

    if root.cnt == 0:
        print -1, -1, -1
        continue

    curmn = root
    curmx = root
    mn = 0
    mx = 0
    for i in range(29,-1,-1):
        b = 1
        if 0 in curmn.down and curmn.down[0].cnt > 0:
            b = 0
        curmn = curmn.down[b]
        mn |= b<<i

        b = 0
        if 1 in curmx.down and curmx.down[1].cnt > 0:
            b = 1
        curmx = curmx.down[b]
        mx |= b<<i

    print mn, mx, float(sm) / root.cnt


import sys


class SovietUF:
    def __init__(self, n):
        self.p = [-1 for _ in range(n)]
        self.nxt = [-1 for _ in range(n)]
        self.fst = [i for i in range(n)]
        self.lst = [i for i in range(n)]

    def find(self, x):
        while self.p[x] >= 0:
            x, self.p[x] = self.p[x], self.p[self.p[x]]
        return x

    def unite(self, x, y):
        xp = self.find(x)
        yp = self.find(y)
        if xp == yp:
            return
        swp = False
        if self.p[xp] > self.p[yp]:
            xp, yp = yp, xp
            swp = True
        self.p[xp] += self.p[yp]
        self.p[yp] = xp
        if swp:
            self.fst[xp] = self.fst[yp]
            self.nxt[self.lst[yp]] = self.fst[xp]
        else:
            self.lst[xp] = self.lst[yp]
            self.nxt[self.lst[xp]] = self.fst[yp]


n, q = map(int, sys.stdin.readline().strip().split())
if n == 2:
    state = 0
    for _ in range(q):
        inp = input().strip().split()
        if inp[0] == "a":
            if inp[1] == inp[2]:
                continue
            if inp[1] == "1":
                state = 1
            if inp[1] == "2":
                state = 2
        elif inp[0] == "b":
            state = 0
        elif inp[0] == "c":
            if state != 0:
                print(state)
            else:
                print(inp[1])
        else:
            assert False
else:
    suf = SovietUF(n)
    for _ in range(q):
        inp = input().strip().split()
        if inp[0] == "a":
            x, y = map(int, inp[1:])
            suf.unite(x - 1, y - 1)
        elif inp[0] == "b":
            continue
        elif inp[0] == "c":
            p = suf.find(int(inp[1]) - 1)
            sys.stdout.write(str(suf.fst[p] + 1) + "\n")

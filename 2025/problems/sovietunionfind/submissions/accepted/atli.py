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
            self.nxt[self.lst[yp]] = self.fst[xp]
            self.fst[xp] = self.fst[yp]
        else:
            self.nxt[self.lst[xp]] = self.fst[yp]
            self.lst[xp] = self.lst[yp]

    def balkanise(self, x):
        xp = self.find(x)
        todo = [self.fst[xp]]
        while self.nxt[todo[-1]] != -1:
            todo.append(self.nxt[todo[-1]])
        for y in todo:
            self.p[y] = -1
            self.fst[y] = y
            self.lst[y] = y
            self.nxt[y] = -1


n, q = map(int, sys.stdin.readline().strip().split())
suf = SovietUF(n)
for _ in range(q):
    inp = input().strip().split()
    if inp[0] == "a":
        x, y = map(int, inp[1:])
        suf.unite(x - 1, y - 1)
    elif inp[0] == "b":
        suf.balkanise(int(inp[1]) - 1)
    elif inp[0] == "c":
        p = suf.find(int(inp[1]) - 1)
        sys.stdout.write(str(suf.fst[p] + 1) + "\n")

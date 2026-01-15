import sys

n, q = map(int, input().strip().split())
if n <= 1000:
    rules = [[i] for i in range(n)]
    ruled_by = [i for i in range(n)]
    for _ in range(q):
        inp = input().strip().split()
        if inp[0] == "a":
            x, y = map(int, inp[1:])
            x, y = x - 1, y - 1
            x, y = ruled_by[x], ruled_by[y]
            if x == y:
                continue
            for z in rules[y]:
                rules[x].append(z)
                ruled_by[z] = x
            rules[y] = []
        elif inp[0] == "b":
            x = int(inp[1]) - 1
            x = ruled_by[x]
            todo = rules[x][:]
            for z in todo:
                ruled_by[z] = z
                rules[z] = [z]
        elif inp[0] == "c":
            x = int(inp[1]) - 1
            print(ruled_by[x] + 1)
        else:
            assert False
else:

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

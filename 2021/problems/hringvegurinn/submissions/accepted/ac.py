#!python3
import sys

class Node:
    def __init__(self, l, r, x = 0):
        self.l = l
        self.r = r
        self.x = x
        self.lazy = 0
    def update(self, v):
        self.x = v
    def range_update(self, v):
        self.lazy = v
    def apply(self):
        self.x += self.lazy * (self.r - self.l + 1)
        self.lazy = 0
    def push(self, u):
        u.lazy += self.lazy

def Join(a, b):
    return Node(a.l, b.r, a.x + b.x)

class SegmentTree:
    def __init__(self, a):
        self.arr = [Node(None, None) for i in range(4 * len(a))]
        self.mk(a, 0, 0, len(a) - 1)
    def mk(self, a, i, l, r):
        m = (l + r) // 2
        if l > r:
            self.arr[i] = Node(l, r)
        elif l == r:
            self.arr[i] = Node(l, r, a[l])
        else:
            self.arr[i] = Join(self.mk(a, 2 * i + 1, l, m), self.mk(a, 2 * i + 2, m + 1, r))
        return self.arr[i]
    def update(self, at, v, i = 0):
        self.propagate(i)
        hl, hr = self.arr[i].l, self.arr[i].r
        if at < hl or hr < at:
            return self.arr[i]
        if hl == at and hr == at:
            self.arr[i].update(v)
            return self.arr[i]
        self.arr[i] = Join(self.update(at, v, 2 * i + 1), self.update(at, v, 2 * i + 2))
        return self.arr[i]
    def query(self, l, r, i = 0):
        self.propagate(i)
        hl, hr = self.arr[i].l, self.arr[i].r
        if r < hl or hr < l:
            return Node(hl, hr)
        if l <= hl and hr <= r:
            return self.arr[i]
        return Join(self.query(l, r, 2 * i + 1), self.query(l, r, 2 * i + 2))
    def range_update(self, l, r, v, i = 0):
        self.propagate(i)
        hl, hr = self.arr[i].l, self.arr[i].r
        if r < hl or hr < l:
            return self.arr[i]
        if l <= hl and hr <= r:
            self.arr[i].range_update(v)
            self.propagate(i)
            return self.arr[i]
        self.arr[i] = Join(self.range_update(l, r, v, 2 * i + 1), self.range_update(l, r, v, 2 * i + 2))
        return self.arr[i]
    def propagate(self, i):
        if self.arr[i].l < self.arr[i].r:
            self.arr[i].push(self.arr[2 * i + 1])
            self.arr[i].push(self.arr[2 * i + 2])
        self.arr[i].apply()


n, q = [int(x) for x in sys.stdin.readline().strip().split()]
sgt = SegmentTree([0 for i in range(n)])
rot = 1

for i in range(q):
    inp = [int(x) for x in sys.stdin.readline().strip().split()]
    if inp[0] == 1:
        rot -= inp[1]
    else:
        inp[1] -= rot
        inp[1] %= n
        inp[1] += n
        inp[1] %= n
        inp[2] -= rot
        inp[2] %= n
        inp[2] += n
        inp[2] %= n
    if inp[0] == 2:
        if inp[1] <= inp[2]:
            sgt.range_update(inp[1], inp[2], inp[3])
        else:
            sgt.range_update(inp[1], n - 1, inp[3])
            sgt.range_update(0, inp[2], inp[3])
    if inp[0] == 3:
        res = 0
        if inp[1] <= inp[2]:
            res += sgt.query(inp[1], inp[2]).x
        else:
            res += sgt.query(inp[1], n - 1).x
            res += sgt.query(0, inp[2]).x
        print(res)


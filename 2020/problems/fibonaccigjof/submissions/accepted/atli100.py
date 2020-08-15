#!/usr/env/bin python3
mod = 10 ** 9 + 7

class Mat2x2:
    def __init__(self, a = 0, b = 0, c = 0, d = 0):
        self.a = a % mod
        self.b = b % mod
        self.c = c % mod
        self.d = d % mod
    def copy(self):
        return Mat2x2(self.a, self.b, self.c, self.d)
    def __add__(self, o):
        return Mat2x2(self.a + o.a, self.b + o.b, self.c + o.c, self.d + o.d)
    def __mul__(self, o):
        _a = self.a * o.a + self.b * o.c
        _b = self.a * o.b + self.b * o.d
        _c = self.c * o.a + self.d * o.c
        _d = self.c * o.b + self.d * o.d
        return Mat2x2(_a, _b, _c, _d)
    def __pow__(self, n):
        res = Mat2x2(1, 0, 0, 1)
        base = self.copy()
        while n > 0:
            if n % 2 == 1:
                res = res * base
            base = base * base
            n //= 2
        return res

fib = Mat2x2(1, 1, 1, 0)

class Node:
    def __init__(self, a, b, x = None):
        if x is None:
            self.l = a.l
            self.r = b.r
            self.x = a.x + b.x
        else:
            self.l = a
            self.r = b
            self.x = x
        self.lazy = Mat2x2(1, 0, 0, 1)
    def range_update(self, d):
        self.lazy = d
    def apply(self):
        self.x = self.x * self.lazy
        self.lazy = Mat2x2(1, 0, 0, 1)
    def push(self, u):
        u.lazy = u.lazy * self.lazy

class SegmentTree:
    def __init__(self, a):
        self.n = len(a)
        self.arr = [None for i in range(4 * len(a))]
        self.mk(a, 0, 0, n - 1)
    def mk(self, a, i, l, r):
        m = (l + r) // 2
        if l > r:
            self.arr[i] = Node(l, r, Mat2x2())
        elif l == r:
            self.arr[i] = Node(l, r, a[l])
        else:
            self.arr[i] = Node(self.mk(a, 2 * i + 1, l, m), self.mk(a, 2 * i + 2, m + 1, r))
        return self.arr[i]
    def query(self, l, r, i = 0):
        self.propagate(i)
        hl, hr = self.arr[i].l, self.arr[i].r
        if r < hl or hr < l:
            return Node(hl, hr, Mat2x2())
        if l <= hl and hr <= r:
            return self.arr[i]
        return Node(self.query(l, r, 2 * i + 1), self.query(l, r, 2 * i + 2))
    def range_update(self, l, r, v, i = 0):
        self.propagate(i)
        hl, hr = self.arr[i].l, self.arr[i].r
        if r < hl or hr < l:
            return self.arr[i]
        if l <= hl and hr <= r:
            self.arr[i].range_update(v)
            self.propagate(i)
            return self.arr[i]
        self.arr[i] = Node(self.range_update(l, r, v, 2 * i + 1), self.range_update(l, r, v, 2 * i + 2))
        return self.arr[i]
    def propagate(self, i):
        if self.arr[i].l < self.arr[i].r:
            self.arr[i].push(self.arr[2 * i + 1])
            self.arr[i].push(self.arr[2 * i + 2])
        self.arr[i].apply()

n, m = [int(x) for x in input().strip().split()]
ds = [int(x) for x in input().strip().split()]
xs = [fib.copy() ** (ds[i] - 1) for i in range(n)]
st = SegmentTree(xs)
for i in range(m):
    l = [int(x) for x in input().strip().split()]
    if l[0] == 1:
        st.range_update(l[1] - 1, l[2] - 1, fib.copy() ** l[3])
    else:
        print(st.query(l[1] - 1, l[2] - 1).x.a)


#!/usr/bin/env python3
import sys
import cmath
eps = 1e-9

n, m = [int(x) for x in input().strip().split()]
sk = [[], []]

for j in range(2):
    for i in range([n - 1, m - 1][j]):
        q, a = [int(x) for x in input().strip().split()]
        sk[j].append([a, q])

    sk[j].append([10 ** 12, int(input())])

seg = [[], []]

for j in range(2):
    pos = (0, 0)
    for i in range([n, m][j]):
        nxt = (sk[j][i][0], pos[1] + (sk[j][i][0] - pos[0]) * sk[j][i][1] / 100.0)
        seg[j].append([complex(pos[0], pos[1]), complex(nxt[0], nxt[1])])
        pos = nxt[:]

def sectx(p1, p2):
    if p1.imag == 0:
        return p1.real
    if p2.imag == 0:
        return p2.real
    if (p1.imag > 0) == (p2.imag > 0):
        return None
    t = -p1.imag / (p2.imag - p1.imag)
    return p1.real + t * (p2.real - p1.real)

def sect(p1, p2, p3, p4):
    if abs(p1 - p4) < eps or abs(p1 - p3) < eps: return p1
    if abs(p2 - p4) < eps or abs(p2 - p3) < eps: return p2
    res = sectx((p3 - p1) / (p2 - p1), (p4 - p1) / (p2 - p1))
    if res is None:
        return res
    if res < -eps or res > 1 + eps:
        return None
    return res * (p2 - p1) + p1

def xinters(p1, p2, p3, p4):
    if abs(p1.real - p4.real) < eps: return False
    if abs(p2.real - p3.real) < eps: return False
    return True

def slope(p1, p2):
    return (p1.imag - p2.imag)/(p1.real - p2.real)

pr = []
seg[0].sort(key=lambda x:x[0].real)
seg[1].sort(key=lambda x:x[0].real)

i1, i2 = 0, 0

while i1 < len(seg[0]) and i2 < len(seg[1]):
    s1, s2 = seg[0][i1], seg[1][i2]
    if xinters(s1[0], s1[1], s2[0], s2[1]) and abs(slope(s1[0], s1[1]) - slope(s2[0], s2[1])) < eps and sect(s1[0], s1[1], s2[0], s2[1]) is not None:
        sys.exit(0) 
    if s1[1].real < s2[1].real:
        i1 += 1
    else:
        i2 += 1

pr = sorted(pr)
g = []

l = -1
for x in pr:
    if abs(l - x) > 1e-9:
        g.append(x)
        l = x

sys.exit(42)

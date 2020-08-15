#!/usr/bin/env python3
#graphs inputs
import numpy
import pylab
import matplotlib.pyplot as plt
from matplotlib.collections import LineCollection
n, m = map(int, input().strip().split())
a = [(0.0, 0.0)]
b = [(0.0, 0.0)]
l = []
c = []
for i in range(n - 1):
    a.append(list(map(float, input().strip().split())))
    a[-1][0] /= 100.0
a.append([float(input())/100.0, 2.1*a[-1][1]])
for i in range(m - 1):
    b.append(list(map(float, input().strip().split())))
    b[-1][0] /= 100.0
b.append([float(input())/100.0, 2.1*b[-1][1]])
if a[-1][1] > b[-1][1]: b[-1][1] = a[-1][1]
else: a[-1][1] = b[-1][1]

x = 0
for i in range(0, n):
    xx = x + (a[i + 1][1] - a[i][1])*a[i + 1][0]
    l.append([(a[i][1], x), (a[i + 1][1], xx)])
    c.append((1, 0, 0, 1))
    x = xx

x = 0
for i in range(0, m):
    xx = x + (b[i + 1][1] - b[i][1])*b[i + 1][0]
    l.append([(b[i][1], x), (b[i + 1][1], xx)])
    c.append((0, 0, 1, 1))
    x = xx

lc = LineCollection(l, colors=c, linewidths=2)
fig, ax = pylab.subplots()
ax.add_collection(lc)
ax.autoscale()
ax.margins(0.1)
plt.show()

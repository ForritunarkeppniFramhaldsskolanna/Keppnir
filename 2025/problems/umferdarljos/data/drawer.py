import matplotlib.pyplot
import matplotlib.collections

import random
import sys

plt = matplotlib.pyplot
n = int(input())
segments = []
colors = []
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    seg = [(x1, y1), (x2, y2)]
    segments.append(seg)
    colors.append(tuple(random.uniform(0, 0.9) for _ in range(3)))

lc = matplotlib.collections.LineCollection(segments, linewidths=1, colors=colors)
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
ax.add_collection(lc)
ax.autoscale()

x = [i[0] for j in segments for i in j]
y = [i[1] for j in segments for i in j]
c = [col for col in colors for _ in (0, 1)]
s = [1 for _ in c]

ax.scatter(x, y, c=c, s=s)

plt.savefig(sys.argv[1])

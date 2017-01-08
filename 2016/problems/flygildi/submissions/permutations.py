from itertools import permutations
import sys
import math
n = int(sys.stdin.readline().strip())

pts = []
for i in range(n):
    x,y = map(int,sys.stdin.readline().strip().split())
    pts.append((x,y))

def dist(a,b, c,d):
    return math.sqrt(pow(a-c,2.0) + pow(b-d,2.0))

mnd = 100000000000000000000.0
for perm in permutations(pts):
    lst = [(0,0)] + list(perm) + [(0,0)]
    dst = 0.0
    for ((a,b),(c,d)) in zip(lst, lst[1:]):
        dst += dist(a,b, c,d)
    mnd = min(mnd, dst)

print('%0.6f' % mnd)


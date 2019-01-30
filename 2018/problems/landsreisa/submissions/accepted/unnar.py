from heapq import *
from random import randint
import time as ti
from math import sqrt
n = int(raw_input())
cities = [tuple(map(float, raw_input().split())) for i in range(n)]
left = set()
x, y = cities[0]
bst = 10**15
ans = []
dist = [[] for i in range(n)]

def calc(x,y,i):
    return (x-cities[i][0])**2 + (y-cities[i][1])**2

start = ti.time()*1000
last = 0
while ti.time()*1000-start < start+950-last:
    left = set()
    x, y = cities[0]
    L = [0]
    dist = [[] for i in range(n)]
    for i in range(n):
        for j in range(n):
            if i == j: continue
            dist[i].append((calc(cities[i][0], cities[i][1], j), j))
        heapify(dist[i])

    for i in range(1,n):
        left.add(i)

    sm = 0
    for i in range(1,n):
        mn = (10**16, 10**16)
        mni = -1
        for j in left:
            q = (0,-1)
            while dist[j]:
                q = dist[j][0]
                if q[1] in left:
                    break
                else:
                    heappop(dist[j])
            d = (calc(x,y,j) + q[0]/i, calc(x,y,j))
            if d < mn:
                mn = d
                mni = j
            elif d == mn and randint(0,100) < 66:
                mn = d
                mni = j
        L.append(mni)
        sm += sqrt(calc(x,y,L[i]))
        x, y = cities[mni]
        left.remove(mni)
    sm += sqrt(calc(x,y,0))
    if sm < bst:
        ans = L
        bst = sm
    last = ti.time()*1000-last

print(' '.join(str(x) for x in ans))
#print(bst)

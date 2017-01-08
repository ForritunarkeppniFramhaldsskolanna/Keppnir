import sys
from Queue import PriorityQueue

n = int(sys.stdin.readline())
ev = []
for i in range(n):
    l,r = map(int,sys.stdin.readline().strip().split())
    ev.append((l, 1, r))

for x in map(int, sys.stdin.readline().strip().split()):
    ev.append((x, 2, 0))

pq = PriorityQueue()
ev = sorted(ev)
for (t, op, v) in ev:
    if op == 1:
        pq.put(v)
    elif op == 2:
        cur = None
        while not pq.empty():
            cur = pq.get()
            if cur < t:
                cur = None
            else:
                break
        if cur is None:
            print 'Neibb'
            sys.exit(0)
    else:
        assert False

print 'Jebb'


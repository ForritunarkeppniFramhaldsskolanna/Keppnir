import sys
from random import randint
from random import shuffle

def randstr():
    s = ''
    for i in range(5):
        cap = randint(0,1)
        if cap:
            s += chr(ord('A') + randint(0,25))
        else:
            s += chr(ord('a') + randint(0,25))
    return s

minN, maxN, minM, maxM, tp = map(int, sys.argv[1:6])
n,m = -1,-1
while True:
    n = randint(minN, maxN)
    m = 0
    if tp == 1:
        m = n*(n-1)//2
    else:
        m = randint(minM if tp == 0 else max(n-1, minM), min(n*(n-1)//2-1, maxM))
    if minN <= n <= maxN and (tp == 1 or minM <= m <= maxM):
        break

sys.stdout.write("%d %d\n" % (n,m))

names = set()
while len(names) < n:
    names.add(randstr())

names = list(names)

sys.stdout.write(' '.join(names) + '\n')

shuffle(names)


pairs = set()
if tp == 1:
    for i in range(n):
        for j in range(i+1,n):
            pairs.add((i,j))
else:
    if tp == 2:
        for i in range(n-1):
            pairs.add((i, i+1))
    while len(pairs) < m:
        i = randint(0,n-2)
        j = randint(i+1,n-1)
        pairs.add((i,j))

for pair in pairs:
    less = randint(0,1)
    if less:
        sys.stdout.write("%s %s %s\n" % (names[pair[0]], '<', names[pair[1]]))
    else:
        sys.stdout.write("%s %s %s\n" % (names[pair[1]], '>', names[pair[0]]))


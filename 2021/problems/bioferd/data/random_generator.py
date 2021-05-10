import sys
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
tp = sys.argv[2]

print('%d' % n)
if tp == 'random':
    for i in range(n):
        dens = random.random()
        arr = []
        for j in range(n):
            if random.random() < dens:
                arr.append(j+1)
        print('%s' % ' '.join(map(str, [len(arr)]+arr)))
elif tp == 'choose':
    perm = list(range(1,n+1))
    es = set( (i+1,p) for i,p in enumerate(perm) )
    all_es = [ (i,j) for i in range(1,n+1) for j in range(1,n+1)  ]
    random.shuffle(all_es)
    for (u,v) in all_es[:random.randint(0, len(all_es))]:
        es.add((u,v))
    bucket = [ [] for _ in range(n) ]
    for (u,v) in es:
        bucket[u-1].append(v)
    for i in range(n):
        arr = bucket[i]
        print('%s' % ' '.join(map(str, [len(arr)]+arr)))


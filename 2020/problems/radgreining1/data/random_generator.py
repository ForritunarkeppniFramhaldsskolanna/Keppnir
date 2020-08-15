import sys
import math
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
m = int(sys.argv[2])
method = sys.argv[3]

ans = ''.join([ random.choice('GTAC') for _ in range(n) ])

arr = []
for i in range(m):
    cnt = min(int(math.ceil(abs(random.gauss(0, 20)))), n)
    start = random.randint(0,n-cnt)
    arr.append((start, ans[start:start+cnt]))

if method == 'singleerror':
    start, s = arr[0]

    at = random.randint(start, start + len(s) - 1)
    err = random.choice(list(set('GTAC') - set([ans[at]])))

    cnt = min(int(math.ceil(abs(random.gauss(0, 20)))), n)
    start = random.randint(max(0, at-cnt+1), at)
    here = ans[start:start+cnt]
    here = list(here)
    here[at - start] = err
    here = ''.join(here)
    arr[-1] = (start, here)

sys.stdout.write('%d %d\n' % (n, m))
random.shuffle(arr)
for s, t in arr:
    sys.stdout.write('%d %s\n' % (s+1, t))


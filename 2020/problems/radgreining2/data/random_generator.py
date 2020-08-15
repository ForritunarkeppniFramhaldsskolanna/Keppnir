import sys
import math
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
m = int(sys.argv[2])
min_cnt = int(sys.argv[3])
max_cnt = int(sys.argv[4])
method = sys.argv[5]
cnt_method = sys.argv[6]

ans = ''.join([ random.choice('GTAC') for _ in range(n) ])

arr = []
for i in range(m):
    if cnt_method == 'small':
        cnt = min(int(math.ceil(abs(random.gauss(0, 20)))), n)
    elif cnt_method == 'random':
        cnt = random.randint(min_cnt, min(max_cnt, n))
    elif cnt_method == 'large':
        cnt = n - min(int(math.floor(abs(random.gauss(0, 20)))), n)

    cnt = max(cnt, min_cnt)
    cnt = min(cnt, max_cnt)
    start = random.randint(0,n-cnt)
    arr.append((start, ans[start:start+cnt]))

if method == 'singleerror':
    start, s = arr[0]

    at = random.randint(start, start + len(s) - 1)
    err = random.choice(list(set('GTAC') - set([ans[at]])))

    cnt = min(int(math.ceil(abs(random.gauss(0, 20)))), n)
    cnt = max(cnt, min_cnt)
    cnt = min(cnt, max_cnt)
    start = random.randint(max(0, at-cnt+1), at)
    here = ans[start:start+cnt]
    here = list(here)
    here[at - start] = err
    here = ''.join(here)
    arr[-1] = (start, here)

for i in range(len(arr)):
    if random.randint(0,1) == 1:
        arr[i] = (arr[i][0], arr[i][1][::-1])

sys.stdout.write('%d %d\n' % (n, m))
random.shuffle(arr)
for s, t in arr:
    sys.stdout.write('%d %s\n' % (s+1, t))


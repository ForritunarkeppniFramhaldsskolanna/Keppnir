from __future__ import print_function
from collections import Counter
import sys

n, k = map(int,sys.stdin.readline().split())
cnt = Counter()
for i in range(n):
    x = int(sys.stdin.readline())
    cnt[x] += 1

found = False
for t in cnt:
    need = 2 if 2*t == k else 1
    if cnt[t] >= need and cnt[k-t] >= need:
        print(t, k - t)
        found = True
        break

if not found:
    print('Neibb')


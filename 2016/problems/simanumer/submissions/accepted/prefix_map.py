import sys
from collections import Counter

n = int(sys.stdin.readline().strip())
C = Counter()
for i in range(n):
    s = sys.stdin.readline().strip()
    for j in range(len(s)+1):
        C[s[:j]] += 1

m = int(sys.stdin.readline().strip())
for i in range(m):
    s = sys.stdin.readline().strip()
    print(C[s])


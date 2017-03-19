import sys
from math import log
n = int(sys.stdin.readline())
c = 0
while (c+1) * log(c+1) / log(10) / 10**6 <= n:
    c += 1
sys.stdout.write('%d\n' % c)

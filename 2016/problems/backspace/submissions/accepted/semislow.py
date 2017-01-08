from __future__ import print_function
import sys
s = sys.stdin.readline().strip()
res = []
for c in s:
    if c == '<':
        res.pop()
    else:
        res.append(c)

print(''.join(res))


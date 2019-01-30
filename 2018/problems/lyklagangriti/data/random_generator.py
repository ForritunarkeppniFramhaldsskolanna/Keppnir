import sys
import string
import random

minN, maxN, tp = map(int, sys.argv[1:4])
n = random.randint(minN, maxN)
choices = string.ascii_lowercase + string.digits
if tp == 1:
    pass
elif tp == 2:
    choices += 'LRB'
elif tp == 3:
    choices += 'B'
elif tp == 4:
    choices += 'LR'
pos = 0
sz = 0
for i in range(n):
    while True:
        c = random.choice(choices)
        if c == 'L' and pos > 0:
            pos -= 1
            break
        elif c == 'R' and pos < sz:
            pos += 1
            break
        elif c == 'B' and pos > 0:
            pos -= 1
            sz -= 1
            break
        elif c in string.ascii_lowercase:
            pos += 1
            sz += 1
            break
    sys.stdout.write(c)
sys.stdout.write('\n')

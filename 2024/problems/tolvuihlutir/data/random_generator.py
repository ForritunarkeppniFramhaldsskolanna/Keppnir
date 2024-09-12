#!/usr/bin/python3
import sys
import random
import math

class StringMaker:
    def __init__(self):
        self.l = 1
        self.c = ['a']
    def get_next(self):
        ret = ''.join(self.c)
        for i in range(len(self.c)):
            if self.c[i] == 'Z':
                self.c[i] = 'a'
            else:
                self.c[i] = chr(ord(self.c[i]) + 1)
                if self.c[i] == '{':
                    self.c[i] = 'A'
                return ret
        self.l += 1
        self.c = ['a' for i in range(self.l)]
        return ret

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_k = eval(sys.argv[2]) 
max_g = eval(sys.argv[3]) 
max_t = eval(sys.argv[4]) 

n = random.choice([max_n, random.randint(max_n // 2, max_n)])
k = random.choice([n, 1, 2, int(math.sqrt(n))])
if max_t == 1:
    k = n
k = min(k, max_k)

counts = []
if k == n:
    counts = [1 for _ in range(n)]
elif k == 1:
    counts = [n]
elif k == 2:
    counts = [random.randint(1, n - 1)]
    counts.append(n - counts[-1])
else:
    counts = [random.randint(1, 10) for _ in range(k)]
    counts[-1] += n - sum(counts)

maker = StringMaker()
names = [maker.get_next() for _ in range(k)]
random.shuffle(names)

p = random.randint(10 ** 8, 10 ** 9)
targ = random.randint(max_g // 10, max_g)

print(n, k, p)
print(*names)

parts = []
for i in range(k):
    for _ in range(counts[i]):
        v = random.randint(p // k // 2, 3 * p // k // 2)
        v = min(10 ** 9, v)
        t = (v - p // k // 2) / (p // k)
        g = int(targ // 2 + t * targ)
        g = max(0, g)
        g = min(g, max_g)
        parts.append((names[i], v, g))

random.shuffle(parts)
for part in parts:
    print(*part)


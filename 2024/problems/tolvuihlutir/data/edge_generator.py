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

n = eval(sys.argv[1])
typ = sys.argv[2]
maker = StringMaker()

if typ == "typemissing":
    print(2, 2, 100)
    print("CPU GPU")
    print("CPU 20 50")
    print("CPU 40 80")

if typ == "cheapestbest":
    k = int(math.sqrt(n))
    p = 10 ** 9
    print(n, k, p)
    names = [maker.get_next() for _ in range(k)]
    random.shuffle(names)
    print(*names)
    parts = []
    for i in range(k):
        parts.append((names[i], 0, 10 ** 5))
    for i in range(n - k):
        name = random.choice(names)
        v = random.randint(0, 10 ** 9)
        g = random.randint(0, 10 ** 5)
        parts.append((name, v, g))
    random.shuffle(parts)
    for part in parts:
        print(*part)

if typ == "expensivebest":
    k = int(math.sqrt(n))
    p = 10 ** 9
    print(n, k, p)
    names = [maker.get_next() for _ in range(k)]
    random.shuffle(names)
    print(*names)
    parts = []
    for i in range(n):
        name = random.choice(names)
        v = random.randint(0, 10 ** 4)
        g = 10 * v
        parts.append((name, v, g))
    random.shuffle(parts)
    for part in parts:
        print(*part)

if typ == "longforward":
    max_g = eval(sys.argv[3])
    k = 20
    p = 10 ** 9
    print(n, k, p)
    names = [maker.get_next() for _ in range(k)]
    random.shuffle(names)
    print(*names)
    counts = [2 for i in range(k)]
    counts[-1] += n - sum(counts)
    parts = []
    for i in range(k):
        parts.append((names[i], 0, 0))
        parts.append((names[i], p // k, max_g))
    for i in range(counts[-1] - 2):
        t = random.uniform(0, 1)
        v = int(p // k * t)
        g = int(max_g * t)
        parts.append((names[-1], v, g))
    random.shuffle(parts)
    for part in parts:
        print(*part)
    
if typ == "longbackward":
    max_g = eval(sys.argv[3])
    k = 20
    p = 10 ** 9
    print(n, k, p)
    names = [maker.get_next() for _ in range(k)]
    random.shuffle(names)
    print(*names)
    counts = [2 for i in range(k)]
    counts[-1] += n - sum(counts)
    parts = []
    for i in range(k):
        parts.append((names[i], 0, 0))
        parts.append((names[i], p // (k - 3), max_g))
    for i in range(counts[-1] - 2):
        t = random.uniform(0, 1)
        v = int(p // (k - 3) * t)
        g = int(max_g * t)
        parts.append((names[-1], v, g))
    random.shuffle(parts)
    for part in parts:
        print(*part)

#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
q = int(sys.argv[2])
three = sys.argv[3] == 'True'
random.seed(int(sys.argv[4]))

class Trie:
    def __init__(self):
        self.down = {}
        self.cnt = 0

    def add_random(self, l, fst):
        if l == 0:
            if self.cnt > 0:
                return False
            self.cnt += 1
            return True
        while True:
            nxt = random.choice(list(self.down.keys()) + [int(random.choice(string.digits))])
            if nxt == 0 and fst:
                continue
            break
        if nxt not in self.down:
            self.down[nxt] = Trie()
        return self.down[nxt].add_random(l-1, False)

    def get_all(self):
        for i in range(self.cnt):
            yield ''
        for (k,v) in self.down.items():
            for x in v.get_all():
                yield str(k)+x

    def random_path(self, l):
        if l == 0:
            return ''
        c = random.choice(list(self.down.keys()))
        return str(c) + self.down[c].random_path(l-1)

nums = Trie()
for i in range(n):
    while True:
        if nums.add_random(7,True):
            break

ss = list(nums.get_all())
print(len(ss))
random.shuffle(ss)
for s in ss:
    print(s)

print(q)
for i in range(q):
    l = random.randint(1,7)
    if three:
        l = 3
    if random.randint(0,4) == 0:
        s = ''
        for j in range(l):
            while True:
                nxt = random.choice(string.digits)
                if nxt == '0' and j == 0:
                    continue
                break
            s += nxt
        print(s)
    else:
        print(nums.random_path(l))


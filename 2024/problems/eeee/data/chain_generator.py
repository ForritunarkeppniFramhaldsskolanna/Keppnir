#!/usr/bin/python3
import sys, random, math

class StringMaker:
    def __init__(self):
        self.l = 1
        self.c = ['A']
    def get_next(self):
        ret = ''.join(self.c)
        for i in range(len(self.c)):
            if self.c[i] == 'Z':
                self.c[i] = 'A'
            else:
                self.c[i] = chr(ord(self.c[i]) + 1)
                return ret
        self.l += 1
        self.c = ['A' for i in range(self.l)]
        return ret

random.seed(int(sys.argv[-1]))
n = eval(sys.argv[1])
g = [[] for i in range(n)]

maker = StringMaker()
lower_maker = StringMaker()
print(n)
lst = maker.get_next()
names = [lst]
print(lst, 0)
for i in range(1, n):
    nw = maker.get_next()
    refs = [lst]
    nums = random.randint(0, 5)
    for j in range(nums):
        refs.append(lower_maker.get_next().lower())
    nums = random.randint(0, 2)
    for j in range(nums):
        refs.append(lst)
    print(nw, len(refs), *refs)
    lst = nw
    names.append(lst)

#!/usr/bin/python3
import sys
import random
import heapq


class SampleSet:
    def __init__(self, items=None):
        self.list = []
        self.locs = dict()
        if items is not None:
            for item in items:
                self.locs[item] = len(self.list)
                self.list.append(item)

    def has_item(self, item):
        return item in self.locs

    def rand_item(self):
        ind = random.randint(0, len(self.list) - 1)
        return self.list[ind]

    def add_item(self, item):
        if item in self.locs:
            return
        self.locs[item] = len(self.list)
        self.list.append(item)

    def rem_item(self, item):
        if item not in self.locs:
            return
        if self.locs[item] != len(self.list) - 1:
            i, j = self.locs[item], len(self.list) - 1
            x, y = self.list[i], self.list[j]
            self.list[i], self.list[j] = y, x
            self.locs[x], self.locs[y] = j, i
        del self.locs[item]
        self.list.pop()

    def __len__(self):
        return len(self.list)


# random.seed(int(sys.argv[-1]))

max_n = int(sys.argv[1])
max_q = int(sys.argv[2])
allow_add = int(sys.argv[3])
allow_rem = int(sys.argv[4])

n = random.choice([max_n, random.randint(max_n // 2, max_n)])
q = random.choice([max_q, random.randint(max_q // 2, max_q)])

print(n, q)

par = [1]
for i in range(1, n):
    p = random.randint(1, i)
    par.append(p)
print(" ".join([str(x) for x in par]))

avail_inds = [n]
in_use = SampleSet(range(n))

for _ in range(q):
    x = in_use.rand_item()
    if random.randint(1, 3) == 1 and allow_add:
        y = heapq.heappop(avail_inds)
        if len(avail_inds) == 0:
            avail_inds = [y + 1]
        in_use.add_item(y)
        print("+", x + 1)
    elif random.randint(1, 2) == 1 and allow_rem and len(in_use) > 1:
        while x == 0:
            x = in_use.rand_item()
        in_use.rem_item(x)
        heapq.heappush(avail_inds, x)
        print("-", x + 1)
    else:
        print("?", x + 1)

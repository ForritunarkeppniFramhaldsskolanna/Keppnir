#!/usr/bin/python3
import sys
import random


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


random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "failing":
    print(9, 10)
    print("1 1 1 3 2 3 3 2 5")
    print("?", 9)
    print("-", 9)
    print("?", 6)
    print("+", 7)
    print("+", 1)
    print("?", 10)
    print("?", 8)
    print("-", 10)
    print("-", 6)
    print("?", 5)

if typ == "deleteall-s":
    n = 10
    q = 10
    print(n, q)
    par = [1]
    for i in range(1, n):
        p = random.randint(1, i)
        par.append(p)
    print(" ".join([str(x) for x in par]))
    to_del = list(range(1, n))
    random.shuffle(to_del)
    for x in to_del:
        print("-", x + 1)
    print("? 1")

if typ == "deleteall":
    n = 100
    q = 100
    print(n, q)
    par = [1]
    for i in range(1, n):
        p = random.randint(1, i)
        par.append(p)
    print(" ".join([str(x) for x in par]))
    to_del = list(range(1, n))
    random.shuffle(to_del)
    for x in to_del:
        print("-", x + 1)
    print("? 1")

if typ == "ordertest-s":
    n = 10
    print(n, 10)
    par = [1] + list(range(1, n))
    print(" ".join([str(x) for x in par]))
    print("+ 1")
    print("+ 1")
    print("?", n + 1)
    print("?", n + 2)
    print("? 8")
    print("- 7")
    print("? 8")
    print("- 6")
    print("? 8")
    print("? 9")

if typ == "ordertest":
    n = 100
    print(n, 25)
    par = [1] + list(range(1, n))
    print(" ".join([str(x) for x in par]))
    print("+ 1")
    print("+ 1")
    print("+ 1")
    print("+ 1")
    print("+ 1")
    print("?", n + 3)
    print("?", n + 4)
    print("?", n + 5)
    print("? 18")
    print("- 17")
    print("? 18")
    print("- 11")
    print("- 98")
    print("- 16")
    print("- 5")
    print("- 13")
    print("+ 1")
    print("+ 5")
    print("? 11")
    print("+ 1")
    print("+ 1")
    print("+ 1")
    print("+ 1")
    print("+ 1")
    print("?", n + 6)


if typ == "raiseclump":
    n = 200000
    q = 200000

    print(n, q)

    order = list(range(1, n))
    random.shuffle(order)
    order = [0] + order
    par = [1] + [None for _ in range(n - 1)]
    for i in range(1, n):
        par[order[i]] = order[i - 1] + 1
    print(" ".join([str(x) for x in par]))

    in_use = SampleSet(range(n))
    cur_mx = n
    for i in range(100000):
        if i % 10 == 7:
            x = in_use.rand_item()
            print("?", x + 1)
        else:
            print("+", order[-1] + 1)
            in_use.add_item(cur_mx)
            cur_mx += 1
    cur_ind = len(order) - 1
    for i in range(100000):
        if i % 87 == 11:
            x = in_use.rand_item()
            print("?", x + 1)
        else:
            print("-", order[cur_ind] + 1)
            in_use.rem_item(order[cur_ind])
            cur_ind -= 1

if typ == "deadchain":
    n = 200000
    q = 200000

    print(n, q)

    order = list(range(1, n))
    random.shuffle(order)
    order = [0] + order
    par = [1] + [None for _ in range(n - 1)]
    for i in range(1, n):
        par[order[i]] = order[i - 1] + 1
    print(" ".join([str(x) for x in par]))

    for i in range(500, 100000 + 500):
        print("?", order[i] + 1)
        print("-", order[i] + 1)

if typ == "spreadchain":
    n = 200000
    q = 200000

    print(n, q)

    order = list(range(1, n // 2))
    random.shuffle(order)
    order = [0] + order
    par = [1] + [None for _ in range(n - 1)]
    for i in range(1, n // 2):
        par[order[i]] = order[i - 1] + 1
    for i in range(n // 2, n):
        par[i] = order[-1] + 1
    print(" ".join([str(x) for x in par]))
    print("? 1")
    for x in order[1:]:
        print("-", x + 1)
    for i in range(n // 2 + n // 4, n):
        print("?", i + 1)
        print("-", i + 1)

if typ == "maxnumber":
    n = 200000
    q = 200000

    print(n, q)

    order = list(range(1, n))
    random.shuffle(order)
    order = [0] + order
    par = [1] + [None for _ in range(n - 1)]
    for i in range(1, n):
        par[order[i]] = order[i - 1] + 1
    print(" ".join([str(x) for x in par]))

    for i in range(q - 1):
        print("+", random.randint(1, n + i))
    print("?", n + q - 1)

if typ == "repclimb":
    n = 200000
    q = 200000 - 1

    print(n, q)

    par = [i - 2 if i % 2 == 0 else i - 1 for i in range(n)]
    par[0] = 0
    print(" ".join([str(x + 1) for x in par]))

    for i in range(2, n, 2):
        print("-", i + 1)
    for i in range(n - 1, -1, -2):
        print("?", i + 1)

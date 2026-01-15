#!/usr/bin/env python3

import sys
import random
import string

allowed_letters = string.ascii_lowercase


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


def make_name(name_length):
    name_list = []
    for _ in range(name_length):
        name_list.append(random.choice(allowed_letters))
    name = "".join(name_list)
    return name


random.seed(sys.argv[-1])
max_n = int(sys.argv[1])

n = max_n

print(n)

names = SampleSet()

if sys.argv[2][0] not in "0123456789":
    typ = sys.argv[2]

    if typ == "addrem":
        for _ in range(n // 2):
            if random.randint(0, 99) == 0:
                q = ""
                if len(names) > 0 and random.randint(1, 2) == 1:
                    q = names.rand_item()
                else:
                    q = make_name(random.randint(3, 8))
                print("?", q)
            else:
                to_add = make_name(random.randint(3, 8))
                while to_add in names.locs:
                    to_add = make_name(random.randint(3, 8))
                names.add_item(to_add)
                print("+", to_add)
        for _ in range(n // 2):
            if random.randint(0, 99) == 0 or len(names) == 0:
                q = ""
                if len(names) > 0 and random.randint(1, 2) == 1:
                    q = names.rand_item()
                else:
                    q = make_name(random.randint(3, 8))
                print("?", q)
            else:
                to_rem = names.rand_item()
                print("-", to_rem)
                names.rem_item(to_rem)

    if typ == "addq":
        for _ in range(n // 2):
            to_add = make_name(random.randint(3, 8))
            while to_add in names.locs:
                to_add = make_name(random.randint(3, 8))
            names.add_item(to_add)
            print("+", to_add)
        for _ in range(n // 2):
            q = ""
            if len(names) > 0 and random.randint(1, 3) != 1:
                q = names.rand_item()
            else:
                q = make_name(random.randint(3, 8))
            print("?", q)
else:
    add_prob = int(sys.argv[2])
    rem_prob = int(sys.argv[3])

    for _ in range(n):
        ch = random.randint(0, 99)

        if len(names) > 0 and ch < rem_prob:
            to_rem = names.rand_item()
            print("-", to_rem)
            names.rem_item(to_rem)
        elif (len(names) > 0 and ch >= rem_prob + add_prob) or add_prob == 0:
            q = ""
            if random.randint(1, 2) == 1 and len(names) > 0:
                q = names.rand_item()
            else:
                q = make_name(random.randint(3, 8))
            print("?", q)
        else:
            to_add = make_name(random.randint(3, 8))
            while to_add in names.locs:
                to_add = make_name(random.randint(3, 8))
            print("+", to_add)
            names.add_item(to_add)

#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

digs = "𝋠𝋡𝋢𝋣𝋤𝋥𝋦𝋧𝋨𝋩𝋪𝋫𝋬𝋭𝋮𝋯𝋰𝋱𝋲𝋳"

l1, l2 = [], []
d1 = random.randint(0, 8)
d2 = random.randint(0, 8)
for _ in range(d1):
    l1.append(random.choice(digs))
for _ in range(d2):
    l2.append(random.choice(digs))
if l1 == []:
    l1 = [digs[0]]
if l2 == []:
    l2 = [digs[0]]
if len(l1) > 1 and l1[0] == digs[0]:
    l1[0] = digs[1]
if len(l2) > 1 and l2[0] == digs[0]:
    l2[0] = digs[1]

print("{} + {}".format("".join(l1), "".join(l2)))

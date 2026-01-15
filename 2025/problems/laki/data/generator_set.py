#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

s1, s2 = set(), set()
l1 = random.randint(0, 100)
l2 = random.randint(0, 100)

for _ in range(l1):
    x = random.randint(0, 99)
    s1.add(x)

for _ in range(l1):
    x = random.randint(0, 99)
    s2.add(x)

s1 = sorted(list(s1))
s2 = sorted(list(s2))

pr = "{} + {}".format(str(s1), str(s2))
pr = pr.replace("[", "{")
pr = pr.replace("]", "}")
print(pr)

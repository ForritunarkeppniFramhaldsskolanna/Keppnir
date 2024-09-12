#!/usr/bin/python3
from collections import defaultdict
from itertools import combinations, product
import random
import sys
MIN_DIFF = -1
MAX_DIFF = 1
MIN_NUM = 1
MAX_NUM = 100

random.seed(int(sys.argv[-1]))
cool_diff = int(sys.argv[1])
cont_diff = int(sys.argv[2])


def cmp(a, b):
    return 0 if a == b else 1 if a > b else -1

factorings = defaultdict(set)
for cool in range(MIN_NUM, MAX_NUM+1):
    for cont in range(MIN_NUM, MAX_NUM+1):
        factorings[cool*cont].add((cool, cont))

counter_examples = defaultdict(set)
for (a, b) in product(range(MIN_NUM, MAX_NUM+1), repeat=2):
    for (c, d) in product(range(MIN_NUM, MAX_NUM+1), repeat=2):
        cmp1 = cmp(a*b, c*d)
        if cmp1 == 0:
            continue
        cmp2 = cmp((a + cool_diff) * (b + cont_diff ), (c + cool_diff) * (d + cont_diff))
        if cmp1 != cmp2:
            counter_examples[(cool_diff, cont_diff)].add(((a, b), (c, d)))

print(2)
(a, b), (c, d) = random.choice(list(counter_examples[(cool_diff, cont_diff)]))
print(f"a {a} {b}")
print(f"b {c} {d}")

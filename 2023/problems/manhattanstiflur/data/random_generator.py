#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

def random_cut(n, m):
    x1 = random.randint(0, n)
    y1 = random.randint(0, m)
    x2, y2 = x1, y1
    if random.randint(1, 2) == 1:
        x2 += random.choice([1, -1])
    else:
        y2 += random.choice([1, -1])
    if x2 < 0: x2 += 2
    if y2 < 0: y2 += 2
    if x2 > n: x2 -= 2
    if y2 > m: y2 -= 2
    return (x1, y1, x2, y2)


max_q = eval(sys.argv[1])
max_n = eval(sys.argv[2])
n, m = -1, -1

if max_n == 1:
    n = 1
    m = random.randint(250, 500)
elif max_n == 2:
    n = 2
    m = random.randint(250, 500)
else:
    max_n = min(max_n, max_q // 2)
    n = random.randint(max_n // 2, max_n)
    m = random.randint(max_n // 2, max_n)
print(max_q)
print(n, m)


if random.randint(1, 2) == 1 or n <= 2:
    # completely random
    for i in range(max_q):
        print(*random_cut(n, m))
else:
    # will have a cut through
    cuts = []
    pos = (0, 0)
    if random.randint(1, 2) == 1:
        pos = (random.randint(1, n - 1), 0)
    else:
        pos = (n, random.randint(0, m - 1))
    while pos[0] != 0 and pos[1] != m:
        nxt = pos
        if random.randint(1, 5) <= 2:
            nxt = (nxt[0] - 1, nxt[1])
        elif random.randint(1, 3) <= 2:
            nxt = (nxt[0], nxt[1] + 1)
        elif random.randint(1, 2) == 1 and nxt[0] < n:
            nxt = (nxt[0] + 1, nxt[1])
        elif nxt[1] > 0:
            nxt = (nxt[0], nxt[1] - 1)
        if nxt == pos:
            continue
        cuts.append((pos[0], pos[1], nxt[0], nxt[1]))
        pos = nxt
    while len(cuts) < max_q:
        cuts.append(random_cut(n, m))
    random.shuffle(cuts)
    while len(cuts) > max_q:
        cuts.pop()
    for cut in cuts:
        print(*cut)

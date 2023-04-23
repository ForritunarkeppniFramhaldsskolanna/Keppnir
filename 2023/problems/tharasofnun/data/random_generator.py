#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

c = eval(sys.argv[1])
r = eval(sys.argv[2])
q = eval(sys.argv[3])
force_order = bool(eval(sys.argv[4]))

print(c, r)
print(q)

t_cur = 0

assert(r * c >= q)

if not force_order:
    if c * r > 5 * q:
        used = set()
        used.add((0, 0))
        for i in range(q):
            t_step = random.randint(0, min([r, c, 10 ** 12 // q]))
            if random.randint(1, 10) == 1:
                t_step = 0
            t_cur += t_step
            ci = random.randint(0, c - 1)
            ri = random.randint(0, r - 1)
            while (ci, ri) in used:
                ci = random.randint(0, c - 1)
                ri = random.randint(0, r - 1)
            print(t_cur, ci, ri)
            used.add((ci, ri))
    else:
        poss = []
        for i in range(c):
            for j in range(r):
                if i == 0 and j == 0:
                    continue
                poss.append((i, j))
        random.shuffle(poss)
        for i in range(q):
            t_cur += random.randint(0, 5)
            ci, ri = poss[-1]
            poss.pop()
            print(t_cur, ci, ri)
else:
    parts = random.randint(q // min(r, c) + 1, 1000)
    used = set()
    used.add((0, 0))
    t = 0
    for i in range(parts):
        qhere = q // parts
        if i < q % parts:
            qhere += 1
        cur = []
        taken_rows, taken_cols = set(), set()
        while len(cur) < qhere:
            ci, ri = 0, 0
            while (ci, ri) in used or ci in taken_cols or ri in taken_rows:
                ci = random.randint(0, c - 1)
                ri = random.randint(0, r - 1)
            cur.append((ci, ri))
            used.add((ci, ri))
            taken_cols.add(ci)
            taken_rows.add(ri)
        vel = random.randint(1, 4)
        if vel == 1:
            cur.sort(key=lambda p: p[0])
        if vel == 2:
            cur.sort(key=lambda p: p[1])
        if vel == 3:
            cur.sort(key=lambda p: -p[0])
        if vel == 4:
            cur.sort(key=lambda p: -p[1])
        for (ci, ri) in cur:
            t_step = random.randint(0, min([r, c, 10 ** 18 // q]))
            if random.randint(1, 10) == 1:
                t_step = 0
            t += t_step
            print(t, ci, ri)
        t += r + c


#!python3
import re

q = int(input())

for i in range(q):
    roll = input().strip()
    r = int(input())
    parts = re.split('([+-])', roll)
    mn, mx, ex, exshf = 0, 0, 0, 0
    lastneg = False
    onlyoneexpl = True
    for p in parts:
        if p == '':
            continue
        if p == '+' or p == '-':
            lastneg = p == '-'
            continue
        if 'd' not in p:
            val = -int(p) if lastneg else int(p)
            mn += val
            mx += val
            exshf += val
            continue
        expl = p[-1] == '!'
        if expl:
            p = p[:-1]
        n, m = p.split('d')
        n, m = int(n), int(m)
        if expl:
            if ex == 0 and n == 1:
                ex = m
            else:
                onlyoneexpl = False
            if lastneg:
                mn = -10 ** 100
            else:
                mx = 10 ** 100
        elif m != 1:
            onlyoneexpl = False
        else:
            exshf += -n if lastneg else n
        mn += -n * m if lastneg else n
        mx += -n if lastneg else n * m
    if r < mn or r > mx:
        print('Svindl')
    elif onlyoneexpl and ex != 0 and (r - exshf) % ex == 0:
        print('Svindl')
    else:
        print('Raunhaeft')
    

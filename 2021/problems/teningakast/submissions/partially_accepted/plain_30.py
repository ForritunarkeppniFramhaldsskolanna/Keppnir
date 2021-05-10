#!python3
import re

q = int(input())

for i in range(q):
    roll = input().strip()
    r = int(input())
    parts = re.split('([+-])', roll)
    mn, mx = 0, 0
    lastneg = False
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
            continue
        expl = p[-1] == '!'
        if expl:
            p = p[:-1]
        n, m = p.split('d')
        n, m = int(n), int(m)
        mn += -n * m if lastneg else n
        mx += -n if lastneg else n * m
    if mn <= r and r <= mx:
        print('Raunhaeft')
    else:
        print('Svindl')
        
    

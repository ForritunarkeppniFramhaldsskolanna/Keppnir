#!/usr/env/bin python3
vwl = ['a', 'e', 'i', 'o', 'u', 'y']
vwl = vwl + [x.upper() for x in vwl]
nm = [str(x) for x in range(10)]
alw = vwl + nm + [' ']
inp, s = input(), []

for c in inp:
    if c in alw:
        s.append(c)

print(''.join(s))

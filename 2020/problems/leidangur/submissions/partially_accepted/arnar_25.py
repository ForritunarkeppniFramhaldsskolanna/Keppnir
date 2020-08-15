#!/usr/bin/python3
s = input()
p,g,o = 0,0,0
for x in s:
    if x == 'p':
        p += 1
    if x == 'g':
        g += 1
    if x == 'o':
        o += 1

print(p)
print(g)
print(o)

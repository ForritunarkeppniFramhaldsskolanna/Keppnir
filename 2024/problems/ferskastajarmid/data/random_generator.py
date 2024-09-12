#!/usr/bin/python3
import sys, random, math

random.seed(int(sys.argv[-1]))

coll = eval(sys.argv[1])
max_n = eval(sys.argv[2])

nams = set()
vals = set()

chars = ['.', '_']
for i in range(ord('a'), ord('z') + 1):
    chars.append(chr(i))
for i in range(ord('A'), ord('Z') + 1):
    chars.append(chr(i))
for i in range(ord('0'), ord('9') + 1):
    chars.append(chr(i))

n = random.choice([max_n, random.randint(1, max_n)])

def gen_name():
    return "".join([random.choice(chars) for j in range(50)])

print(n)
for i in range(n):
    x, y = random.randint(0, 100), random.randint(0, 100)
    while coll and x * y in vals:
        x, y = random.randint(0, 100), random.randint(0, 100)
    if not coll and random.randint(1, 3) == 1 and len(vals) > 0:
        ml = random.choice(list(vals))
        divs = []
        j = 1
        while j * j <= ml:
            if ml % j == 0:
                divs.append(j)
                if j * j != ml:
                    divs.append(ml // j)
            j += 1
        if len(divs) == 0:
            x = 0
            y = random.randint(0, 100)
            if random.randint(1, 2) == 2:
                x, y = y, x
        else:
            x, y = 1000, 1000
            while x > 100 or y > 100:
                x = random.choice(divs)
                y = ml // x
    nam = gen_name()
    while nam in nams:
        nam = gen_name()
    nams.add(nam)
    vals.add(x * y)
    print(nam, x, y)



import sys
import random

def next_num(x, m):
    l = [x]
    i = 2
    while i*i < x:
        if x%i == 0:
            l.append(i)
            l.append(x//i)
        i += 1
    if x%i == 0: l.append(i)
    y = l[random.randint(0, len(l) - 1)]
    return y*random.randint(1, m//y)

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
m = int(sys.argv[2])
p = int(sys.argv[3])

if p == 1:
    print(n)
    for i in range(n):
        print(random.randint(1, m), end = '')
        if i != n - 1: print(end = ' ')
    print()
else:
    print(n)
    x = random.randint(1, m//10)
    l = []
    for i in range(n):
        l.append(x)
        x = next_num(x, m)
    random.shuffle(l)
    for i in range(n):
        print(l[i], end = '')
        if i != n - 1: print(end = ' ')
    print()

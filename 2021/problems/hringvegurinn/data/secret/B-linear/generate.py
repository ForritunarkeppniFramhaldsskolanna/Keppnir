import random

n = random.randint(1, 10 ** 6)
q = random.randint(1, 10 ** 4)
print(n, q)

for i in range(q):
    c = random.randint(2, 3)
    if c == 1:
        print(1, random.randint(1, n))
    elif c == 2:
        l = random.randint(1, n)
        r = random.randint(1, n)
        if l > r:
            l, r = r, l
        print(2, l, r, random.randint(1, 10 ** 9))
    else:
        l = random.randint(1, n)
        r = random.randint(1, n)
        if l > r:
            l, r = r, l
        print(3, l, r)

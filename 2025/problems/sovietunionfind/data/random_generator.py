#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "GA":
    print(2, 100)
    for _ in range(100):
        x = random.randint(1, 2)
        y = random.randint(1, 2)
        if random.randint(1, 3) == 1:
            print("a", x, y)
        elif random.randint(1, 2) == 1:
            print("b", x)
        else:
            print("c", x)

if typ == "rand":
    n = int(sys.argv[2])
    q = int(sys.argv[3])
    useb = int(sys.argv[4])
    print(n, q)
    for _ in range(q):
        x = random.randint(1, n)
        y = random.randint(1, n)
        if random.randint(1, 3) == 1:
            print("a", x, y)
        elif random.randint(1, 2) == 1 and useb:
            print("b", x)
        else:
            print("c", x)

if typ == "longchain":
    n = int(sys.argv[2])
    print(n, 2 * (n - 1))
    shuf = [i for i in range(n)]
    random.shuffle(shuf)
    for i in range(1, n):
        x = shuf[i]
        par = shuf[random.randint(0, i - 1)]
        print("a", x + 1, par + 1)
        j = shuf[random.randint(0, i - 1)]
        print("c", j + 1)

if typ == "balkan":
    n = int(sys.argv[2])
    q = int(sys.argv[3])
    b = int(sys.argv[4])
    print(n, q)
    while q > 0:
        sz = random.randint(1, min(b, q))
        q -= sz
        inds = random.sample(range(n), sz)
        for j in range(1, len(inds)):
            print("a", inds[j - 1] + 1, inds[j] + 1)
        if q > 0:
            print("c", random.choice(inds) + 1)
            q -= 1
        print("b", random.choice(inds) + 1)
        if q > 0:
            print("c", random.choice(inds) + 1)
            q -= 1

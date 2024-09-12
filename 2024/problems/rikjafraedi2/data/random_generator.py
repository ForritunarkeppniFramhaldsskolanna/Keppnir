#!/usr/bin/python3
import random
import sys

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
q = int(sys.argv[2])
typ = sys.argv[3]

if typ == "emptycheck":
    n = min(n, q // 2)
    print(n, 2 * n)
    queries = [(1, x, x) for x in range(1, n + 1)]
    for _ in range(n):
        x = random.randint(1, n)
        y = random.randint(1, n)
        queries.append((1, x, y))
    random.shuffle(queries)
    for o, x, y in queries:
        print(o, x, y)

if typ == "random":
    print(n, q)
    for _ in range(q):
        o = random.randint(0, 1)
        x = random.randint(1, n)
        y = random.randint(1, n)
        print(o, x, y)

if typ == "buckets":
    bucket_sz = int(sys.argv[4])
    print(n, q)
    for _ in range(q):
        x = random.randint(1, n)
        y = random.randint(1, n)
        if random.randint(1, 2) == 1:
            print(1, x, y)
        else:
            if x // bucket_sz == y // bucket_sz:
                print(0, x, y)
            else:
                print(0, min(x, y), max(x, y))

if typ == "transitive":
    order = [i for i in range(n)]
    random.shuffle(order)
    print(n, q)
    for _ in range(q):
        x = random.randint(1, n)
        y = random.randint(1, n)
        if random.randint(1, 10) == 1:
            while y == x:
                y = random.randint(1, n)
            if order[x - 1] > order[y - 1]:
                x, y = y, x
            print(0, x, y)
        else:
            print(1, x, y)


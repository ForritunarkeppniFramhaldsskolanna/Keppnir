import sys
from random import randint, choice
from collections import defaultdict

adj = set()
n,q = 0,0
e = 0
def make_queries():
    global n,q
    print(n, q)
    for i in range(q):
        t = randint(1,2)
        if t == 1 and e <= n*(n-1)//2:
            a, b = make_edge()
            print(t, a, b)
        if t == 2:
            print(t, randint(1,n))


def make_edge():
    global n, e
    e += 1
    while True:
        a = randint(1,n)
        b = randint(1,n)
        if a != b and (a,b) not in adj:
            adj.add((a,b))
            adj.add((b,a))
            return a,b

tc = int(sys.argv[1])
if tc == 1:
    n = randint(1, 1000)
    q = randint(1, 1000)
    make_queries()
if tc == 2:
    n = randint(1, 10**5)
    q = randint(1, 10**5)
    print(n, q)
    edges = randint(0, min(q, n*(n-1)//2))
    for i in range(edges):
        a,b = make_edge()
        print(1, a, b)
    for i in range(q-edges):
        a = randint(1, n)
        print(2, a)
if tc == 3:
    n = randint(1, 10**5)
    q = randint(1, 10**5)
    make_queries()
        


import random
import sys

def describe(A):
    return [ A.count(i) for i in range(len(A)) ]

def random_seq(n):
    return [ random.randint(0, n - 1) for i in range(n) ]

n = int(input())

iters = 20000
while iters > 0:
    iters -= 1
    seen = set()
    x = random_seq(n)
    while True:
        y = describe(x)
        if x == y:
            print(' '.join(map(str, x)))
            sys.exit(0)

        if tuple(x) in seen:
            break

        seen.add(tuple(x))
        x = describe(x)

print('Engin')


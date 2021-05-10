import sys
import random

random.seed(int(sys.argv[-1]))

def miller_rabin(n, k):
    if n == 2:
        return True

    if n % 2 == 0 or n < 2:
        return False

    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = random.randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

n = eval(sys.argv[1])
k = eval(sys.argv[2])
tp = sys.argv[3]

if tp == 'max':
    print('%d %d' % (n-k+1, n))
elif tp == 'maxprimes':
    a = n-k+1
    b = n
    while not miller_rabin(a, 20):
        a += 1
    while not miller_rabin(b, 20):
        b -= 1
    print('%d %d' % (a, b))
elif tp == 'random':
    a = random.randint(1, n)
    b = random.randint(max(1, a-k+1), min(a+k-1, n))
    if a > b:
        a, b = b,a
    print('%d %d' % (a, b))


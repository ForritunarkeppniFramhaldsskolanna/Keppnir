import sys

def is_witness(n, a):
    if a > n-2:
        return False
    d = n-1
    r = 0
    while d % 2 == 0:
        r += 1
        d /= 2
    x = pow(a, d, n)
    if x == 1 or x == n-1:
        return False
    for i in range(r-1):
        x = x * x % n
        if x == 1:
            return True
        if x == n-1:
            return False
    return True

def is_probable_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    if n < 2047: a = [2]
    elif n < 1373653: a = [2, 3]
    elif n < 9080191: a = [31, 73]
    elif n < 25326001: a = [2, 3, 5]
    elif n < 3215031751: a = [2, 3, 5, 7]
    elif n < 4759123141: a = [2, 7, 61]
    elif n < 1122004669633: a = [2, 13, 23, 1662803]
    elif n < 2152302898747: a = [2, 3, 5, 7, 11]
    elif n < 3474749660383: a = [2, 3, 5, 7, 11, 13]
    elif n < 341550071728321: a = [2, 3, 5, 7, 11, 13, 17]
    elif n < 3825123056546413051: a = [2, 3, 5, 7, 11, 13, 17, 19, 23]
    elif n < 18446744073709551616: a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
    else: assert False

    for x in a:
        if is_witness(n, x):
            return False
    return True

def is_prime(x):
    if x <= 1:
        return False
    i = 2
    while i*i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

n = int(sys.stdin.readline())
a = 2
while True:
    if is_prime(a):
        for b in range(a+1):
            if is_prime(b) and is_probable_prime(n - a - b):
                print a, b, n-a-b
                sys.exit(0)
    a += 1


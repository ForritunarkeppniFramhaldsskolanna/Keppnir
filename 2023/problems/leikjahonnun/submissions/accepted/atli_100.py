#!/usr/bin/python3
import cmath
import math
import sys

def fft(x, inv = False):
    n = len(x)
    j = 0
    for i in range(n):
        if i < j: 
            x[i], x[j] = x[j], x[i]
        m = n >> 1
        while 1 <= m and m <= j:
            j -= m
            m >>= 1
        j += m
    mx = 1
    while mx < n:
        theta, w = math.pi / mx, 1
        if inv:
            theta = -theta
        wp = math.cos(theta) + math.sin(theta) * 1j
        for m in range(mx):
            for i in range(m, n, mx << 1):
                t = x[i + mx] * w
                x[i + mx] = x[i] - t
                x[i] += t
            w *= wp
        mx <<= 1
    if inv:
        for i in range(n):
            x[i] /= n

mxsz = 262144
p, q = [], []

def read_to():
    a = [complex(0) for i in range(mxsz)]
    inp = [int(x) for x in sys.stdin.readline().strip().split()]
    for x in inp[1:]:
        a[x] += 1
    fft(a)
    return (inp[0], a)

n = int(sys.stdin.readline().strip())
denom, p = read_to()
for i in range(1, n):
    d, q = read_to()
    denom *= d
    for j in range(mxsz):
        p[j] *= q[j]
fft(p, True)
for i in range(mxsz):
    x = int(round(abs(p[i])))
    if x == 0:
        continue
    g = math.gcd(x, denom)
    sys.stdout.write("{} {}/{}\n".format(i, x // g, denom // g))

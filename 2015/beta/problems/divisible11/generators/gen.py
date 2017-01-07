import random
import string
import subprocess

ts = [
    ('n', 10),
    ('n', 10),
    ('n', 22),
    ('n', 11),
    ('n', 22),
    ('n', 100),
    ('n', 1000),
    ('d', 10**10),
    ('d', 10**100),
    ('d', 10**1000),
    ('d', 10**1000),
    ('d', 10**1000),
    ('d', 10**1000),

    ('d', 11),
    ('d', 22),
    ('d', 100),
    ('d', 1000),
    ('d', 10**10),
    ('d', 10**100),
    ('d', 10**1000),
    ('d', 10**1000),
    ('d', 10**1000),
    ('d', 10**1000),
]

for t, (tp, mx) in enumerate(ts):

    while True:
        n = random.randint(1, mx)
        if (n % 11 == 0) == (tp == 'd'):
            break

    with open('%02d.in' % t, 'w') as f:
        f.write('%d\n' % n)


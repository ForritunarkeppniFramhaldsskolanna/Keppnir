import random

ts = [
    (1,1),
    (1,5),
    (1,10),
    (1,100),
    (10,100),
    (100,1000),
    (1000,10000),
    (10000,100000),
    (100000,1000000),
    (1000000,10000000),
    (1000000,10000000),
    (1000000,10000000),
    (1000000,10000000),
    (1000000,10000000),
    (1000000,10000000),
    (1000000,10000000),
]

for t, (a, b) in enumerate(ts):
    with open('%02d.in' % t, 'w') as f:
        f.write('%d\n' % random.randint(a, b))


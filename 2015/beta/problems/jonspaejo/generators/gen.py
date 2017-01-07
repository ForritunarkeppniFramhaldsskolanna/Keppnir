import random

ts = [
    (3, 3),
    (5, 5),
    (10, 0),
    (100, 0),
    (10, 1),
    (100, 1),
    (10, 2),
    (10, 3),
    (100, 3),
    (10, 4),
    (100, 4),
    (10, 5),
    (100, 5),
    (6, 6),
    (7, 6),
    (100, 6),
    (10, 7),
    (100, 7),
    (10, 8),
    (100, 8),
    (100, 9),
    (100, 10),
    (100, 12),
    (100, 20),
    (100, 30),
    (100, 50),
    (100, 90),
    (100, 100),
]

for t, (n, k) in enumerate(ts):
    with open('%02d.in' % t, 'w') as f:

        s = [ str(random.randint(0, 9)) for i in range(n - k) ]
        for i in range(k):
            j = random.randint(0, len(s))
            s = s[:j] + ['?'] + s[j:]

        f.write('%s\n' % ''.join(s))


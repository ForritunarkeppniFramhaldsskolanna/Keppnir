import random
import string
import subprocess

ts = [
    (1, 1),
    (26, 1),
    (1, 2),
    (2, 2),
    (10, 2),
    (20, 2),
    (26, 2),
    (1, 4),
    (2, 4),
    (10, 4),
    (20, 4),
    (26, 4),
    (1, 100),
    (2, 100),
    (10, 100),
    (20, 100),
    (26, 100),
    (1, 1000),
    (2, 1000),
    (10, 1000),
    (20, 1000),
    (26, 1000),
]

for t, (cnt, height) in enumerate(ts):

    heights = [ random.randint(1, height) for i in range(cnt) ]
    height = max(heights)

    with open('%02d.in' % t, 'w') as f:
        for i in range(height, 0, -1):
            for j in range(cnt):
                f.write('|' if heights[j] >= i else ' ')
            f.write('\n')

        s = list(string.ascii_uppercase)
        random.shuffle(s)
        f.write(''.join(s[:cnt]) + '\n')


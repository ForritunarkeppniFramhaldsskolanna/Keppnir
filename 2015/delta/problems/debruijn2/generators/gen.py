import random
import string
import subprocess

ts = [
    ('random', 2, 1),
    ('random', 2, 2),
    ('random', 2, 3),
    ('random', 2, 4),
    ('random', 2, 5),
    ('random', 2, 10),
    ('random', 2, 17),
    ('random', 3, 3),
    ('random', 3, 5),
    ('random', 5, 2),
    ('random', 5, 4),
    ('random', 5, 4),
    ('random', 26, 2),
    ('debruijn', 2, 1),
    ('debruijn', 2, 2),
    ('debruijn', 2, 3),
    ('debruijn', 2, 4),
    ('debruijn', 2, 5),
    ('debruijn', 2, 10),
    ('fdebruijn', 2, 17),
    ('debruijn', 3, 3),
    ('debruijn', 3, 5),
    ('debruijn', 5, 2),
    ('debruijn', 5, 4),
    ('debruijn', 5, 4),
    ('debruijn', 6, 5),
    ('debruijn', 26, 2),
    ('almostdebruijn', 2, 1),
    ('almostdebruijn', 2, 2),
    ('almostdebruijn', 2, 3),
    ('almostdebruijn', 2, 4),
    ('almostdebruijn', 2, 5),
    ('almostdebruijn', 2, 10),
    ('falmostdebruijn', 2, 17),
    ('almostdebruijn', 3, 3),
    ('almostdebruijn', 3, 5),
    ('almostdebruijn', 5, 2),
    ('almostdebruijn', 5, 4),
    ('almostdebruijn', 5, 4),
    ('almostdebruijn', 6, 5),
    ('almostdebruijn', 26, 2),
]

for t, (tp, k, n) in enumerate(ts):

    alpha = string.ascii_lowercase[:k]

    if tp == 'random':
        s = ''.join([ random.choice(alpha) for i in range(k**n) ])
    elif 'debru' in tp:
        if tp[0] == 'f':
            s = open('%d_%d.txt' % (k, n), 'r').read()
        else:
            while True:
                try:
                    s = subprocess.check_output([ './a.out' ], timeout=2, input=('%d %d' % (k, n)).encode('ascii'))
                    ok = True
                except:
                    # import traceback
                    # traceback.print_exc()
                    # print('failed, retrying', k, n)
                    ok = False

                if ok:
                    break

        s = ''.join([ alpha[int(c)] for c in s.strip().split() ])

        if 'almost' in tp:
            x = random.choice(list(range(len(s))))
            c = s[x]
            nc = random.choice(list(set(alpha) - set([c])))
            s = s[:x] + nc + s[x+1:]

    # print(s)

    with open('%02d.in' % t, 'w') as f:
        f.write('%d %d\n%s\n' % (k, n, s))


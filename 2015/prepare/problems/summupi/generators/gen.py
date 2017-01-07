import random
from decimal import *
getcontext().prec = 100
pi = '3.14159265358979323846'

ts = [
    ('one', '3.1415926534'),
    ('one', '3.1415926535'),
    ('one', '3.1415926536'),
    ('middle', 2),
    ('over', 2),
    ('under', 2),
    ('middle', 3),
    ('middle', 4),
    ('over', 5),
    ('under', 5),
    ('middle', 5),
    ('middle', 6),
    ('middle', 7),
    ('middle', 8),
    ('middle', 9),
    ('middle', 10),
    ('middle', 15),
    ('middle', 19),
    ('middle', 20),
    ('middle', 30),
    ('middle', 32),
    ('middle', 34),
    ('over', 35),
    ('under', 35),
    ('middle', 35),
    ('middle', 35),
    ('middle', 35),
    ('hard', 35),
    ('hard', 35),
    ('hard', 35),
    ('hard', 35),
    ('hard', 35),
    ('hard', 35),
    ('hard', 35),
    ('hard', 35),
]

def rand_char():
    return chr(ord('0') + random.randint(0, 9))

def get_rand():
    return rand_char() + '.' + ''.join( rand_char() for _ in range(10) )

def split(sm, n):
    res = []
    for i in range(n):
        cur = sm * Decimal(random.random())
        sm -= cur
        cur = '%0.10f' % cur
        if cur == '0.0000000000':
            cur = '0.' + ''.join( random.choice(['0','1']) for _ in range(10) )
        res.append(cur)
    return res

for t, (tp, x) in enumerate(ts):
    lst = []

    if tp == 'one':
        lst.append(x)
    elif tp == 'hard':
        lst = split(4 * Decimal(pi), x)
    else:
        while True:
            cur = []
            sm = Decimal('0.0')
            while len(cur) < x:

                while True:
                    nxt = get_rand()
                    if tp == 'over' and Decimal(nxt) <= Decimal(pi):
                        continue
                    if tp == 'under' and Decimal(nxt) >= Decimal(pi):
                        continue
                    # if tp == 'hard' and sm + Decimal(nxt) >= 2 * Decimal(pi):
                    #     continue
                    break

                sm += Decimal(nxt)
                cur.append(nxt)

            if len(cur) < x:
                continue

            lst = cur

            if tp == 'middle':
                if Decimal(min(cur)) < Decimal(pi) and sum( Decimal(y) for y in cur ) > Decimal(pi):
                    break
            elif tp == 'hard':
                if Decimal(min(cur)) < Decimal(pi) and sum( Decimal(y) for y in cur ) > Decimal(pi) and sum( Decimal(y) for y in cur ) <= 2 * Decimal(pi):
                    break
            else:
                break

    random.shuffle(lst)
    with open('%02d.in' % t, 'w') as f:
        f.write('%d\n' % len(lst))
        for s in lst:
            f.write('%s\n' % s)


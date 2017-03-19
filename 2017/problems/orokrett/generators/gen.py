
import random


start = 3
ts = [
    (1, 3, 1, 3, 1, 10),
    (1, 3, 1, 3, 1, 10),
    (2, 8, 1, 3, 1, 10),
    (2, 8, 1, 3, 1, 10),
    (1, 10, 1, 10, 1, 10),
    (1, 10, 1, 10, 1, 10),
    (1, 10, 1, 10, 1, 3),
    (1, 10, 1, 10, 1, 2),
    (1, 10, 1, 10, 1, 2),
    (1, 10, 1, 10, 1, 1),
    (1, 10, 1, 10, 1, 1),
    (1, 10, 1, 10, 1, 1),
    (1, 10, 1, 10, 1, 2),
    (1, 10, 1, 10, 1, 2),
]

allvs = [ chr(ord('a') + i) for i in range(10) ]

for i, (mn_clauses, mx_clauses, mn_vsperclause, mx_vsperclause, mn_vars, mx_vars) in enumerate(ts):

    random.shuffle(allvs)
    vs = allvs[:random.randint(mn_vars, mx_vars)]

    res = ' OR '.join( '(' + ' AND '.join( random.choice(['','!']) + random.choice(vs) for v in range(random.randint(mn_vsperclause, mx_vsperclause)) ) + ')' for c in range(random.randint(mn_clauses, mx_clauses)) )

    with open('%02d.in' % (start + i), 'w') as f:
        f.write('%s\n' % res)


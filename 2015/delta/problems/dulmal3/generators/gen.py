import string
import random

ts = [
    ('bjarki',2),
    ('hjalti',3),
    ('testalissjus',2),
    ('testalissjus',5),
    ('hvaderiganginum',1),
    ('holymolyshit',6),
    ('haha',5),
    ('komduadleika',6),
]

for t, (s, k) in enumerate(ts):
    # s = ''.join( random.choice(string.ascii_lowercase) for i in range(n) )
    r = ''
    for i in range(len(s)):
        r += s[i]

        add = k - 1
        if i == len(s) - 1:
            add = random.randint(0, k - 1)

        r += ''.join( random.choice(string.ascii_lowercase) for j in range(add) )

    with open('%02d.in' % t, 'w') as f:
        f.write('%d\n' % k)
        f.write('%s\n' % r)

    with open('%02d.ans' % t, 'w') as f:
        f.write('%s\n' % s)


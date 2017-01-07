import random
import string

ts = [
    (1,1),
    (20,1),
    (1,2),
    (9,2),
    (20,2),
    (10,3),
    (11,3),
    (12,3),
    (10,10),
    (20,11),
    (20,5),
]

for t, (l, k) in enumerate(ts):
    with open('%02d.in' % t, 'w') as f:
        f.write('%d\n' % k)
        f.write('%s\n' % ''.join([ random.choice(string.ascii_lowercase) for i in range(l) ]))


import random

ts = [
    1,
    1,
    1,
    2,
    2,
    2,
    3,
    4,
    10,
    10,
    10,
    100,
    200,
    300,
    900,
]

for t, l in enumerate(ts):

    start = random.randint(0, 1000 - l)
    end = start + l - 1

    ops = []
    ops.append( ('x >= %d' % start) if random.randint(0, 1) == 0 else ('x > %d' % (start - 1)) )
    ops.append( ('x <= %d' % end) if random.randint(0, 1) == 0 else ('x < %d' % (end + 1)) )

    cnt = random.randint(0, 10 - 2)
    for i in range(cnt):
        while True:
            choose = random.randint(0, 1000)
            if start <= choose <= end:
                continue

            if choose < start:
                ops.append( ('x >= %d' % choose) if random.randint(0, 1) == 0 else ('x > %d' % choose) )
            else:
                ops.append( ('x <= %d' % choose) if random.randint(0, 1) == 0 else ('x < %d' % choose) )

            break

    random.shuffle(ops)

    with open('%02d.in' % t, 'w') as f:
        f.write('%d\n' % len(ops))
        for s in ops:
            f.write('%s\n' % s)

    with open('%02d.ans' % t, 'w') as f:
        for i in range(start, end + 1):
            f.write('%d\n' % i)


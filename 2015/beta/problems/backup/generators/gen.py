import random
import string

ts = [
    (1, 1),
    (3, 1),
    (5, 1),
    (10, 1),
    (100, 1),
    (500, 1),
    (1, 3),
    (3, 3),
    (5, 3),
    (10, 3),
    (100, 3),
    (500, 3),
    (1, 5),
    (3, 5),
    (5, 5),
    (10, 5),
    (100, 5),
    (500, 5),
    (1, 10),
    (3, 10),
    (5, 10),
    (10, 10),
    (100, 10),
    (500, 10),
    (1, 100),
    (3, 100),
    (5, 100),
    (10, 100),
    (100, 100),
    (500, 100),
    (1, 1000),
    (3, 1000),
    (5, 1000),
    (10, 1000),
    (100, 1000),
    (500, 1000),
]

names = set()
def get_rand_name():
    while True:
        l = random.randint(1, 100)
        s = ''.join( random.choice(string.ascii_lowercase) for _ in range(l) )
        if s not in names:
            names.add(s)
            return s

def parse(size):
    suffixes = [
        ('GB', 1024**3),
        ('MB', 1024**2),
        ('KB', 1024**1),
        ('B', 1024**0),
    ]
    for suffix, mult in suffixes:
        if size.endswith(suffix):
            part = int(size[:-len(suffix)])
            assert 1 <= part < 1024
            return mult * part
    assert False

def get_rand_size():
    return '%d%s' % (random.randint(1, 1023), random.choice(['B', 'KB', 'MB', 'GB']))

for t, (n, m) in enumerate(ts):
    print(t)
    with open('%02d.in' % t, 'w') as f:

        while True:
            tries = 100000
            sizes = []
            tot_size = 0
            while tries and len(sizes) < n:
                nxt = get_rand_size()
                if parse(nxt) + tot_size > 1023 * 1024**3:
                    tries -= 1
                    continue
                tot_size += parse(nxt)
                sizes.append(nxt)

            if len(sizes) != n:
                continue

            while True:
                disk_sizes = [ get_rand_size() for _ in range(m) ]
                if tot_size > max( parse(sz) for sz in disk_sizes ): continue
                break
            break

        names = set()
        mnx = 10000000000000000000000000000000000000
        mns = ''

        f.write('%d %d\n' % (n, m))
        for i in range(n):
            f.write('%s %s\n' % (get_rand_name(), sizes[i]))
        for i in range(m):
            name = get_rand_name()
            price = random.randint(1, 2**30)
            f.write('%s %s %d\n' % (name, disk_sizes[i], price))

            if parse(disk_sizes[i]) >= tot_size:
                if price < mnx:
                    mnx = price
                    mns = name

    with open('%02d.ans' % t, 'w') as f:
        f.write('%s\n' % mns)


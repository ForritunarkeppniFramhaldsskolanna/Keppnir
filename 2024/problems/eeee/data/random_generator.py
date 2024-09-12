#!/usr/bin/python3
import sys, random, math

def make_tree(g, ind, l, r):
    if r <= l:
        return
    while random.randint(1, 3) != 1:
        if l == r:
            break
        ch = random.randint(l, r - 1)
        make_tree(g, ind, l, ch)
        g[ind[r]].append(ind[ch])
        l = ch + 1
    if l < r - 1:
        make_tree(g, ind, l, r - 1)

class StringMaker:
    def __init__(self):
        self.l = 1
        self.c = ['A']
    def get_next(self):
        ret = ''.join(self.c)
        for i in range(len(self.c)):
            if self.c[i] == 'Z':
                self.c[i] = 'A'
            else:
                self.c[i] = chr(ord(self.c[i]) + 1)
                return ret
        self.l += 1
        self.c = ['A' for i in range(self.l)]
        return ret

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]
max_n = eval(sys.argv[2])
n = random.randint(3 * max_n // 4, max_n) if random.randint(1, 2) == 1 else max_n
g = [[] for i in range(n)]

if typ == "trivial":
    maker_lower = StringMaker()
    maker_upper = StringMaker()
    acron = [maker_upper.get_next() for i in range(n)]
    words = [maker_lower.get_next().lower() for i in range(30 * n)]
    random.shuffle(acron)
    random.shuffle(words)
    print(n)
    for i in range(n):
        num = random.randint(0, 30)
        use = []
        for j in range(num):
            use.append(words[-1])
            words.pop()
        print(acron[i], num, *use)
    exit(0)

if typ == "tree":
    chunks = random.randint(1, 3)
    buckets = [[] for i in range(chunks)]
    for i in range(n):
        buckets[i % chunks].append(i)
    for i in range(chunks):
        make_tree(g, buckets[i], 0, len(buckets[i]) - 1)
elif typ == "dag":
    order = list(range(n))
    random.shuffle(order)
    e = random.choice([int(n * math.log(n)), int(n ** 1.15), int(n ** 1.25)])
    done = set()
    while len(done) < e:
        a = random.randint(0, n - 1)
        b = random.randint(0, n - 1)
        if a == b:
            continue
        if a > b:
            a, b = b, a
        if (a, b) in done:
            continue
        done.add((a, b))
        g[order[a]].append(order[b])
elif typ == "any":
    chunks = random.randint(6, 20) if random.randint(1, 2) == 1 else random.randint(2, 5)
    buckets = [[] for i in range(chunks)]
    for i in range(n):
        buckets[i % chunks].append(i)
    for i in range(chunks):
        e = int(round(len(buckets[i]) ** 1.2))
        done = set()
        while len(done) < e:
            a = random.randint(0, len(buckets[i]) - 1)
            b = random.randint(0, len(buckets[i]) - 1)
            if (a, b) in done or (b, a) in done:
                continue
            done.add((a, b))
            g[a].append(b)
    random.shuffle(buckets)
    e = int(round(len(buckets) ** 1.25))
    done = set()
    while len(done) < e:
        a_bucket = random.randint(0, len(buckets) - 1)
        b_bucket = random.randint(0, len(buckets) - 1)
        if a_bucket == b_bucket:
            continue
        if b_bucket < a_bucket:
            a_bucket, b_bucket = b_bucket, a_bucket
        a = random.choice(buckets[a_bucket])
        b = random.choice(buckets[b_bucket])
        if (a, b) in done or (b, a) in done:
            continue
        done.add((a, b))
        g[a].append(b)

bait = dict()
for i in range(ord('a'), ord('z') + 1):
    bait[random.randint(0, n - 1)] = chr(i)
maker = StringMaker()
names = [maker.get_next() for i in range(n)]
random.shuffle(names)
print(len(g))
for i in range(len(g)):
    refer = [names[j] for j in g[i]]
    if i in bait:
        refer.append(bait[i])
    random.shuffle(refer)
    print(names[i], len(refer), *refer)

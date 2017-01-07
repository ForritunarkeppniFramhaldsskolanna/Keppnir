import sys
import random
import string

names = set()
def rand_name():
    while True:
        l = random.randint(1, 20)
        name = ''.join([ random.choice(string.ascii_lowercase + '_') for i in range(l) ])
        if name not in names:
            names.add(name)
            return name

n = int(sys.argv[1])
m = int(sys.argv[2])
density = float(sys.argv[3])

assert 1 <= n+m <= 100000

left = [ rand_name() for i in range(n) ]
right = [ rand_name() for j in range(m) ]
both = left + right
random.shuffle(both)

print(len(both))
for x in both:
    print(x)

forbidden = []
for i in range(n):
    for j in range(m):
        if random.random() < density:
            cur = [left[i], right[j]]
            random.shuffle(cur)
            forbidden.append(tuple(cur))

random.shuffle(forbidden)

assert 0 <= len(forbidden) <= 100000

print(len(forbidden))
for x, y in forbidden:
    print("%s %s" % (x, y))


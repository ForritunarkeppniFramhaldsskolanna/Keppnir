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
density = float(sys.argv[2])

assert 1 <= n <= 100000

vertices = [ rand_name() for i in range(n) ]
random.shuffle(vertices)

print(len(vertices))
for x in vertices:
    print(x)

forbidden = []
for i in range(n):
    for j in range(i + 1, n):
        if random.random() < density:
            cur = [vertices[i], vertices[j]]
            random.shuffle(cur)
            forbidden.append(tuple(cur))

random.shuffle(forbidden)

assert 0 <= len(forbidden) <= 100000

print(len(forbidden))
for x, y in forbidden:
    print("%s %s" % (x, y))


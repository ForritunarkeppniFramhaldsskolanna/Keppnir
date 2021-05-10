import sys
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
p = int(sys.argv[2])
appear = int(sys.argv[3])

sort = random.randint(1,4)
missing = random.randint(1,3)
cur = set(range(1,3+1))
cur.remove(missing)

print('%d %d' % (n, p))
for i in range(n):
    if i == appear:
        cur.add(missing)
    print('%d %d' % (sort, random.choice(list(cur))))


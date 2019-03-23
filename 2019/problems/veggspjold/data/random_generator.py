import sys
import random

# Type of testcase:
#   1: min_n
#   2: max_n
#   3: min_a
#   4: max_a
#   5: seed
typ = int(sys.argv[1])
min_size = int(sys.argv[2])
max_size = int(sys.argv[3])
min_n = int(sys.argv[4])
max_n = int(sys.argv[5])
if len(sys.argv) > 6:
    random.seed(int(sys.argv[6]))

n = random.randint(min_n, max_n)
b = random.randint(min_size, max_size)
h = random.randint(min_size, max_size)


def random_low_biased(mn, mx, p=2):
    rnd = random.uniform(0,1)**p
    return int(mn+(mx-mn)*rnd)

arr = []
if typ == 1 or typ == 2:
    cnt = [[0 for _ in range(b+1)] for _ in range(h+1)]
    it = 0
    while len(arr) < n:
        if it >= 100000:
            n = len(arr)
            break
        x1 = random.randint(0,b-1)
        x2 = random_low_biased(x1+1,b)
        y1 = random.randint(0,h-1)
        y2 = random_low_biased(y1+1,h)
        invalid = False
        for i in range(y1, y2+1):
            for j in range(x1, x2+1):
                if cnt[i][j] == typ:
                    invalid = True
                    break
            if invalid:
                break
        if invalid:
            it += 1
            continue
        for i in range(y1, y2+1):
            for j in range(x1, x2+1):
                cnt[i][j] += 1
        arr.append((x1,x2,y1,y2))
elif typ == 3:
    for i in range(n):
        x1 = random.randint(0,b-1)
        x2 = random_low_biased(x1+1,b)
        y1 = random.randint(0,h-1)
        y2 = random_low_biased(y1+1,h)
        arr.append((x1,x2,y1,y2))
else:
    for i in range(n):
        arr.append((0,b,0,h))

sys.stdout.write("%d %d %d\n" % (b, h, n))
for i in range(n):
    sys.stdout.write("%d %d %d %d\n" % arr[i])

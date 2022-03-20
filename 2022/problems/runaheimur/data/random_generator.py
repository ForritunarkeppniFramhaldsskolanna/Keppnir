#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[2])
max_n = int(sys.argv[3])
min_m = int(sys.argv[4])
max_m = int(sys.argv[5])
n = random.randint(min_n, max_n)
m = random.randint(min_m, max_m)

sys.stdout.write("{} {}\n".format(n, m))
if sys.argv[1] == "perm":
    perm_index = int(sys.argv[6])
    from itertools import permutations
    vals = list(list(permutations(range(1, n*m)))[perm_index-1])
else:
    solveable = int(sys.argv[6])

    def inversions(vals):
        return sum(vals[i] > vals[j]
                   for i in range(len(vals))
                   for j in range(i+1, len(vals)))

    while True:
        vals = list(range(1, n*m))
        random.shuffle(vals)
        if inversions(vals) % 2 != solveable:
            break

vals.append(n*m)
for i in range(n):
    sys.stdout.write("{}\n".format(' '.join(str(x) for x in vals[m*i:m*(i+1)])))

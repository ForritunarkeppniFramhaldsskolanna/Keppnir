import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: specific
#   4: Given values
min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
if len(sys.argv) > 3:
    random.seed(int(sys.argv[3]))

n = random.randint(min_n, max_n)

A = [random.randint(-10**9, 10**9) for _ in range(n)]

k = random.choice(A)

sys.stdout.write("%d %d\n"%(n,k))
sys.stdout.write(" ".join([str(x) for x in A]) + "\n")

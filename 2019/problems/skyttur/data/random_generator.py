import sys
import random

# Type of testcase:
#   1: min_n
#   2: max_n
#   3: prob_s
#   4: prob_t
#   5: seed
min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
prob_s = float(sys.argv[3])
prob_t = float(sys.argv[4])
if len(sys.argv) > 5:
    random.seed(int(sys.argv[5]))

n = random.randint(min_n, max_n)
s = ''.join(['1' if random.uniform(0,1) < prob_s else '0' for i in range(n)])
t = ''.join(['1' if random.uniform(0,1) < prob_t else '0' for i in range(n)])
print(str(n))
print(s)
print(t)

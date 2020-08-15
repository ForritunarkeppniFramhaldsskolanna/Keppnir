import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_m = eval(sys.argv[2])
max_l = eval(sys.argv[3])
print(max_n, max_m)
p = sorted(random.sample(range(1, max_l), max_n - 1))
q = sorted(random.sample(range(1, max_l), max_m - 1))
for i in range(max_n - 1):
    print(random.randint(1, 99), p[i])
print(random.randint(1, 99))
for i in range(max_m - 1):
    print(random.randint(1, 99), q[i])
print(random.randint(1, 99))


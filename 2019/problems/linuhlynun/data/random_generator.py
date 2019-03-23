import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_x = eval(sys.argv[2])
max_c = eval(sys.argv[3])

print(max_n)

for i in range(max_n):
    print(random.randint(1, max_x), random.randint(1, max_c))


import sys
import random

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
max_y = eval(sys.argv[2])

print(n)
for i in range(n):
    print(random.randint(1, max_y))


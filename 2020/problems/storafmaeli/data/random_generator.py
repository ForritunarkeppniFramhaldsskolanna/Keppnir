import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
tp = sys.argv[3]

n = 0
if tp == "Jebb":
    n = 1
    while n%10 != 0:
        n = random.randint(min_n, max_n)
elif tp == "Neibb":
    while n%10 == 0:
        n = random.randint(min_n, max_n)
else:
    n = random.randint(min_n, max_n)

print(n)

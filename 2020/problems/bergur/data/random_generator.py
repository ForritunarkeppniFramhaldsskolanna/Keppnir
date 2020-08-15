import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_ai = eval(sys.argv[2])

n = random.randint(1, max_n)
print(n)

A = []
for i in range(n):
    A.append(str(random.randint(1, max_ai)))
print(' '.join(A))


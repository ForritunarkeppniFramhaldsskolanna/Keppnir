import sys
import random

import string

max_n = eval(sys.argv[1])
max_a = eval(sys.argv[2])
max_d = eval(sys.argv[3])

n = random.randint(1,max_n)
d = random.randint(1,max_d)
print(str(n) + " " + str(d) )
L = []
for x in range(n):
    L.append(str(random.randint(1,max_a)))
print(' '.join(L))


import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: Given values


fmax = int(sys.argv[1])
smax = int(sys.argv[2])
n = random.randint(1,fmax)
m = random.randint(1,fmax)
k = random.randint(1,fmax)
print(str(n) + " " + str(m) + " " + str(k))
arr = []
for x in range(n):
    arr.append(str(random.randint(1,smax)))
print(' '.join(arr))
    



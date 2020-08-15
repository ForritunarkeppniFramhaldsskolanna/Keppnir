import sys
import random

# Type of testcase:
#   1: max a_i
#   2: max k
#   3: max n
#   3: min n
n = random.randint(int(sys.argv[4]),int(sys.argv[3]))
k = random.randint(1, min(int(sys.argv[2]),n) )
print(str(n) + " " + str(k))
A = []
for x in range(n):
    A.append(str(random.randint(1,int(sys.argv[1]))))
print(' '.join(A))


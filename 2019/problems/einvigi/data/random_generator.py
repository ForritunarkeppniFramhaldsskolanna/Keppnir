import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: Given values

mn1 = int(sys.argv[3])
mn2 = int(sys.argv[4])
mx1 = int(sys.argv[1])
mx2 = int(sys.argv[2])
kmx = int(sys.argv[5])
n = random.randint(mn1,mx1)
m = random.randint(mn2,n)
k = random.randint(1,kmx)
A = []
B = []
for x in range(n):
    A.append(str(random.randint(1,mx2)))
for x in range(n):
    B.append(str(random.randint(1,mx2)))
print(str(n) + " " + str(m) + " " + str(k))
print(' '.join(A))
print(' '.join(B))
    



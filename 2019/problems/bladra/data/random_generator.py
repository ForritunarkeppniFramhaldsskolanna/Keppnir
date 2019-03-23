import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: Given values

mx = int(sys.argv[1])
n = random.randint(2,mx)
q = random.randint(2,mx)
print(str(n) + " " + str(q))
for x in range(q):
    print(str(random.randint(1,mx)) + " " + str(random.randint(1,n)))



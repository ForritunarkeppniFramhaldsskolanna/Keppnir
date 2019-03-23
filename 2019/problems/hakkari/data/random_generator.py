import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: Given values

st = int(sys.argv[1])
n = random.randint(2,st)
m = random.randint(2,st)
print(str(n) + " " + str(m))
for x in range(n):
    st = ""
    for y in range(m):
        if random.randint(1,2) == 1:
            st += "*"
        else:
            st += "."
    print(st)


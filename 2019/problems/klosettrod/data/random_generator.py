import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: specific
#   4: Given values
n = random.randint(5,1000)
arr = []
for x in range(1,n+1):
    arr.append(str(x))
random.shuffle(arr)
print(n)
print(' '.join(arr))

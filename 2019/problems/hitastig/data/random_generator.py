import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: specific
#   4: Given values
ran = int(sys.argv[1])
n = random.randint(5,1000)
arr = []
for x in range(1,n+1):
    arr.append(str(random.randint(-ran,ran)))
random.shuffle(arr)
print(n)
print(' '.join(arr))

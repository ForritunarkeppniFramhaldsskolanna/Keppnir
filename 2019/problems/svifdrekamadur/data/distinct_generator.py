import random
import sys

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
arr = [ 1+i for i in range(n) ]
random.shuffle(arr)

print(n)
print(' '.join(map(str, arr)))


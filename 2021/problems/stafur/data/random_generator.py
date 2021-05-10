import sys
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])

print(chr(ord('A')+n-1))

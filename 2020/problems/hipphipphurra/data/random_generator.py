import sys
import random
import string

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])

print(''.join( random.choice(string.ascii_letters) for _ in range(random.randint(1,20)) ))
print(n)


import sys
import random
import string

random.seed(int(sys.argv[-1]))

alpha = int(sys.argv[1])
n = int(sys.argv[2])

alpha = string.ascii_lowercase[:alpha]
a = random.randint(1, n)
b = random.randint(1, n)

print(''.join( random.choice(alpha) for _ in range(a) ))
print(''.join( random.choice(alpha) for _ in range(b) ))


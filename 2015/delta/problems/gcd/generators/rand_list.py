import sys
import random

N = random.randint(1,10)
g = random.randint(1,15)
sys.stdout.write('{}\n'.format(N))
lis = []
for i in range(N):
    lis.append(str(random.randint(1,100//g)*g))
sys.stdout.write('{}\n'.format(' '.join(lis)))

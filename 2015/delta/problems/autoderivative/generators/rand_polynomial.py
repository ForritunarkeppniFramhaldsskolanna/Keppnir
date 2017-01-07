import random
import sys


if len(sys.argv) > 1:
    N = int(sys.argv[1])
else:
    N = random.randint(0,100)

sys.stdout.write("{}\n".format(N))
for i in range(N+1):
    if i > 0:
        sys.stdout.write(' ')
    sys.stdout.write(str(random.randint(0,100)))
sys.stdout.write('\n')

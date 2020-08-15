import sys
import random
import string

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])

arr = list(range(0,1001))
random.shuffle(arr)

print(n)
for i in range(n):
    print('%s %d' % (''.join( random.choice(string.ascii_letters) for _ in range(random.randint(1,20)) ), arr[i]))


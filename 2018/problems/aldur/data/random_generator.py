import sys
from random import randint

minN = int(sys.argv[1])
maxN = int(sys.argv[2])
n = randint(minN,maxN)
print(n)
for x in range(n):
    print(randint(0,10**5))


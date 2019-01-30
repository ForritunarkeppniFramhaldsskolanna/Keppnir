import sys
from random import randint
from random import shuffle

minN, maxN = map(int, sys.argv[1:3])
print(randint(minN, maxN))

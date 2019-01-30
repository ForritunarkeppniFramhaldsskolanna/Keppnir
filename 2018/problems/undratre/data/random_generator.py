import sys
from random import randint
from random import shuffle

minN, maxN, minK, maxK = map(int, sys.argv[1:5])
sys.stdout.write("%d %d\n" % (randint(minN, maxN), randint(minK, maxK)))

import sys
from random import randint

tc = int(sys.argv[1])

n = -1
m = -2
if tc == 1:
    n = randint(1,7)
    m = randint(1,7)
if tc == 2:
    n = randint(1,50)
    m = randint(1,50)
if tc == 3:
    n = randint(1,200)
    m = randint(1,200)
if tc == 4:
    n = randint(1,2000)
    m = randint(1,2000)
if tc == 5:
    n = randint(1,10**6)
    m = randint(1,10**6)
if tc == 6:
    n = randint(1,10**18)
    m = randint(1,10**18)
if tc == 7:
    n = int(sys.argv[2])
    m = int(sys.argv[3])

sys.stdout.write("%s %s\n" % (n, m))

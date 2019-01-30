import sys
from random import randint

# Type of testcase:
#   1: small
#   2: large
tc = int(sys.argv[1])

if tc == 1:
    n = randint(2,1000)
    P = randint(1,10)

    print(n, P)
    print(" ".join([str(randint(0,10)) for i in range(n)]))
elif tc == 2:
    n = randint(2,1000000)
    P = randint(1,1000000000)

    print(n, P)
    print(" ".join([str(randint(0,1000)) for i in range(n)]))


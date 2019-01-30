import sys
from random import randint

tc = int(sys.argv[1])
if tc == 0:
    n = randint(1, 1000)
    print(n, 1) 
    for i in range(n):
        print(1, randint(0, 10**6))
elif tc == 1:
    n = randint(1, 1000)
    L = randint(1, 1000)
    l = randint(1, L)
    print(n, L)
    for i in range(n):
        print(randint(1, 1000), l)
elif tc == 2:
    n = randint(2, 1000)
    L = randint(1, 1000)
    print(n, L)
    for i in range(n):
        print(randint(1, L), randint(0, 10**6))
elif tc == 3:
    n = 1000
    L = 1000
    print(n, L)
    for i in range(n):
        print(randint(1,5), randint(0, 10**6))

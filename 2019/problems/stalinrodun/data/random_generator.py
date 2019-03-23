#!/usr/bin/python3
import sys
from random import randint

# tc:
#   1: 1 <= n <= 50
#   2: 1 <= n <= 2.5*10**3
#   3: 1 <= n <= 5*10**5
# _type:
#   1: random
#   2: increasing
#   3: decreasing
#   4: sqrt inc
#   5: sqrt dec
tc = int(sys.argv[1])
_type = int(sys.argv[2])

if tc == 1:
    if _type == 1:
        n = randint(1,50) 
    if _type == 2:
        n = 50
    if _type == 3:
        n = 50
    if _type == 4:
        n = 49
        k = 7
    if _type == 5:
        n = 49
        k = 7
elif tc == 2:
    if _type == 1:
        n = randint(1,2500) 
    if _type == 2:
        n = 2500
    if _type == 3:
        n = 2500
    if _type == 4:
        n = 2500
        k = 50
    if _type == 5:
        n = 2500
        k = 50
elif tc == 3:
    if _type == 1:
        n = randint(1,500000) 
    if _type == 2:
        n = 500000
    if _type == 3:
        n = 500000
    if _type == 4:
        n = 499849
        k = 707
    if _type == 5:
        n = 499849
        k = 707
if _type == 1:
    print(n)
    print(" ".join(map(str, (randint(1, 1000000) for i in range(n)))))
elif _type == 2:
    print(n)
    print(" ".join(map(str, (i+1 for i in range(n)))))
elif _type == 3:
    print(n)
    print(" ".join(map(str, (n-i for i in range(n)))))
elif _type == 4:
    print(n)
    print(" ".join(map(str, (k*i-j for i in range(1,k+1) for j in range(k)))))
elif _type == 5:
    print(n)
    print(" ".join(map(str, (n+1-k*i+j for i in range(1,k+1) for j in range(k)))))

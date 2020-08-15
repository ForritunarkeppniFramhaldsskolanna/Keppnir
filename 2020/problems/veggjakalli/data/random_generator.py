import sys
import random


min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
use_min_n_for_m = eval(sys.argv[3])
t = eval(sys.argv[4])


if t == 3:
    n = max_n
    m = int(max_n/2)
    s = ""
    for x in range(n):
        s += "#"
    print(str(n) + " " + str(m))
    print(s)
else:
    n = random.randint(min_n,max_n)
    m = random.randint(2,n)
    if use_min_n_for_m == 1:
        m = random.randint(min_n,n)


    if t == 2:
        s = ""
        for x in range(n):
            if x == 0 or x == n-1:
                s += "#"
            else:
                s += "-"
    else:
        s = ""
        for x in range(n):
            if x == 0 or x == n-1:
                s += "#"
            else:
                if random.randint(1,3) == 1:
                    s += "#"
                else:
                    s += "-"
    print(str(n) + " " + str(m))
    print(s)


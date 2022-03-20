#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
special_n = eval(sys.argv[2])
special_m = eval(sys.argv[3])

if special_n != -1:
    print(str(special_n) + " " +str(special_m))
else:
    n = random.randint(0,max_n)
    m = random.randint(0,max_n)
    print(str(n) + " " + str(m))

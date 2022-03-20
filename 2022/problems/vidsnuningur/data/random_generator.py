#!/usr/bin/python3
import sys
import random
from string import ascii_letters, digits 

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])

s = ''
for i in range(random.randint(1,max_n)):
    s += random.choice(ascii_letters+digits)
print(s)

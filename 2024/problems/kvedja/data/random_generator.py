#!/usr/bin/python3
import sys
import random
import string


random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

n = random.randint(min_n, max_n)
random_string = ''.join(random.choice(string.ascii_letters) for _ in range(n))
print(random_string)

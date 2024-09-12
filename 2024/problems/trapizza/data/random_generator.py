#!/usr/bin/python3
import sys, random, math

random.seed(int(sys.argv[-1]))

min_d = eval(sys.argv[1])
max_d = eval(sys.argv[2])

min_a = eval(sys.argv[3])
max_a = eval(sys.argv[4])

min_b = eval(sys.argv[5])
max_b = eval(sys.argv[6])

min_h = eval(sys.argv[7])
max_h = eval(sys.argv[8])

print(random.randint(min_d, max_d))
print(random.randint(min_a, max_a))
print(random.randint(min_b, max_b))
print(random.randint(min_h, max_h))

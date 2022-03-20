#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
m = eval(sys.argv[2])
t = eval(sys.argv[3])

sys.stdout.write('%d %d\n' % (n, m))
sys.stdout.write('%s\n' % ' '.join(map(str, [ random.randint(1, t) for i in range(n) ])))


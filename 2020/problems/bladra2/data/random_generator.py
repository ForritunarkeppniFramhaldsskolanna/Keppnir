import sys
import random

bound = int(sys.argv[1])
random.seed(int(sys.argv[-1]))

v = random.randint(-bound, bound)
a = random.randint(-bound, bound)
t = random.randint(0, bound)
sys.stdout.write("%d %d %d\n" % (v,a,t))

import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

n = random.randint(min_n, max_n)
s = "u"*n

sys.stdout.write("{}\n".format(s))

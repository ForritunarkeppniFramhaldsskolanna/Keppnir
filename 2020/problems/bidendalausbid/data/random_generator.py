import sys
import random

random.seed(int(sys.argv[-1]))

tp = sys.argv[1]

if tp == "easy":
    n = random.randint(0, 1439)
    m = random.randint(n, 1439)
else:
    n = random.randint(0, 1439)
    m = random.randint(0, 1439)
    
h1,m1 = n//60, n%60
h2,m2 = m//60, m%60
sys.stdout.write("%d%d:%d%d\n" % (h1//10, h1%10, m1//10, m1%10))
sys.stdout.write("%d%d:%d%d\n" % (h2//10, h2%10, m2//10, m2%10))

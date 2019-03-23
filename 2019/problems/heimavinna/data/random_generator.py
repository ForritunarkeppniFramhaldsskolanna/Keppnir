import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: specific
#   4: Given values
typ = int(sys.argv[1])
if len(sys.argv) > 2:
    random.seed(int(sys.argv[2]))
    
if typ == 1:
    i = random.randint(1, 1000)
    rnd = random.uniform(0,1)**2.5
    l = int(1 + (1000-i-1) * rnd)
    a = i
    b = i+l-1
    if a == b:
        sys.stdout.write("%d\n" % a)
    else:
        sys.stdout.write("%d-%d\n" % (a, b))
elif typ == 2:
    B = []
    i = 1
    while i <= 1000:
        x = random.randint(0,4)
        if x == 0:
            B.append(str(i+1))
            i += 1
        i += 1
    sys.stdout.write(';'.join(B)+'\n')
elif typ == 3:
    i = 1
    B = []
    while i <= 1000:
        x = random.randint(0,3)
        if x == 0:
            rnd = random.uniform(0,1)**2.5
            l = int(1 + (1000-i) * rnd)
            a = i
            b = i+l-1
            assert(a <= b)
            if a == b:
                B.append("%d" % a)
            else:
                B.append("%d-%d" % (a,b))
            i = b+2
        else:
            i += 1
    sys.stdout.write(';'.join(B)+'\n')
else:
    assert(False)

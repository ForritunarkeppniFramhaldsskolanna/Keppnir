import sys
from random import randint
from random import shuffle
m=int(sys.argv[1])

if m==1:
    sys.stdout.write("1\n%d\n"%randint(0,10**8))
if m==2:
    sys.stdout.write("2\n%d %d\n"%(randint(0,10**8),randint(0,10**8)))
if m==3:
    k=randint(0,1)
    if k:
        sys.stdout.write("3\n%d %d %d\n"%(randint(0,10**8),randint(0,10**8),randint(0,10**8)))
    else:
        a=randint(0,10**8)
        b=randint(0,10**8-1)
        if (a^b)&1:
            b+=1
        c=(a+b)>>1
        s=[a,b,c]
        shuffle(s)
        sys.stdout.write("3\n%d %d %d\n"%tuple(s))
if m==4:
    a,b,c,d=[randint(0,10**8) for t in range(4)]
    sys.stdout.write("4\n%d %d %d %d\n"%(a,b,c,d))

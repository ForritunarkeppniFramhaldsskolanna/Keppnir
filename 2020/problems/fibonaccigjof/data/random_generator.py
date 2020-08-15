import sys
import random

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
m = eval(sys.argv[2])
max_x = eval(sys.argv[3])
max_d = eval(sys.argv[4])
method = sys.argv[5]

print('%d %d' % (n,m))

if method == 'random':
    print(' '.join( str(random.randint(1, max_x)) for _ in range(n) ))

    for i in range(m):
        if random.randint(1,2) == 1:
            l = random.randint(1,n)
            r = random.randint(1,n)
            if l > r:
                l, r = r, l
            print('1 %d %d %d' % (l, r, random.randint(1, max_d)))
        else:
            l = random.randint(1,n)
            r = random.randint(1,n)
            if l > r:
                l, r = r, l
            print('2 %d %d' % (l, r))
elif method == 'max1':
    print(' '.join( str(max_x) for _ in range(n) ))

    for i in range(m-1):
        print('1 %d %d %d' % (1, n, max_d))
    print('2 %d %d' % (1, n))

elif method == 'max2':
    print(' '.join( str(max_x) for _ in range(n) ))

    for i in range(m):
        if i % 2 == 0:
            print('1 %d %d %d' % (1, n, max_d))
        else:
            print('2 %d %d' % (1, n))

elif method == 'max3':
    print(' '.join( str(max_x) for _ in range(n) ))

    for i in range(m):
        print('2 %d %d' % (1, n))


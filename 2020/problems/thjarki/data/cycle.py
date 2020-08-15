import sys
import random

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
m = eval(sys.argv[2])
qs = eval(sys.argv[3])
max_k = eval(sys.argv[4])

assert n % 2 == 0

sys.stdout.write('%d %d\n' % (n,m))

for i in range(n):
    for j in range(m):
        if j == 0:
            if i == 0:
                sys.stdout.write('>')
            else:
                sys.stdout.write('^')
        elif i % 2 == 0:
            if j == m-1:
                sys.stdout.write('v')
            else:
                sys.stdout.write('>')
        else:
            if j == 1:
                if i == n-1:
                    sys.stdout.write('<')
                else:
                    sys.stdout.write('v')
            else:
                sys.stdout.write('<')
    sys.stdout.write('\n')

sys.stdout.write('%d\n' % qs)
for q in range(qs):

    if random.randint(0,1) == 0:
        cnt = random.randint(1,max_k)
    else:
        cnt = random.randint(n*m-10, n*m-1)
    cnt = min(cnt, max_k)
    cnt = max(cnt, 1)

    sys.stdout.write('%d %d %d\n' % (random.randint(1,n), random.randint(1,m), cnt))


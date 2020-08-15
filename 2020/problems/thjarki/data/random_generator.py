import sys
import random

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
m = eval(sys.argv[2])
qs = eval(sys.argv[3])
max_k = eval(sys.argv[4])
allowed = sys.argv[5]

sys.stdout.write('%d %d\n' % (n,m))

for i in range(n):
    for j in range(m):
        cur_allowed = set(allowed)
        if i == 0:
            try:
                cur_allowed.remove('^')
            except:
                pass
        if i == n-1:
            try:
                cur_allowed.remove('v')
            except:
                pass
        if j == 0:
            try:
                cur_allowed.remove('<')
            except:
                pass
        if j == m-1:
            try:
                cur_allowed.remove('>')
            except:
                pass
        cur_allowed = list(cur_allowed)
        sys.stdout.write('%s' % random.choice(cur_allowed))
    sys.stdout.write('\n')

sys.stdout.write('%d\n' % qs)
for q in range(qs):
    sys.stdout.write('%d %d %d\n' % (
        random.randint(1,n),
        random.randint(1,m),
        random.randint(1,max_k)))



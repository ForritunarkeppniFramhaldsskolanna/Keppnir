import sys
import random

if len(sys.argv) > 4:
    random.seed(int(sys.argv[-1]))

tp = eval(sys.argv[1])
min_n = eval(sys.argv[2])
max_n = eval(sys.argv[3])

if tp == 1:
    print(random.randint(min_n, max_n))
elif tp == 2:
    s = str(random.randint(min_n-1, max_n-1))
    A = ['2']
    for _ in range(len(s) - 1):
        A.append(random.choice(['0', '2']))
    print(int(''.join(A)))
else:
    print(10**(random.randint(min_n, max_n)))

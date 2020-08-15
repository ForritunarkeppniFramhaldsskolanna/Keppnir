import sys
import random

random.seed(int(sys.argv[-1]))

lo = eval(sys.argv[1])
hi = eval(sys.argv[2])
tp = sys.argv[3]

def case(n):
    if n % 4 == 0:
        if n % 100 == 0:
            if n % 400 == 0:
                return 'd'
            return 'c' 
        return 'b'
    return 'a'

while True:
    n = random.randint(lo, hi)
    if case(n) == tp:
        print(n)
        break


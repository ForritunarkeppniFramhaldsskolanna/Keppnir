import sys
from random import randint

minN, maxN, minQ, maxQ = map(int, sys.argv[1:5])
n = randint(minN, maxN)
q = randint(minQ, maxQ)

print(n)
for i in range(n):
    print(randint(-10**9, 10**9), randint(-10**9, 10**9))
print(q)
for i in range(q):
    print(randint(0, 10**9))

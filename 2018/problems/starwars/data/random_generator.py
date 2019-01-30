import sys
from random import randint

minN, maxN = [int(i) for i in sys.argv[1:3]]
n = 1
while n % 3 != 0:
    n = randint(minN, maxN)

s = set()
while len(s) < n:
    s.add(str(randint(1, 10**9)))

print(n)
print(" ".join(list(s)))
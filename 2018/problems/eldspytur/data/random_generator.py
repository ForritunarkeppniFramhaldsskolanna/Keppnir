import sys
from random import randint
minN, maxN, minK, maxK, result = map(int, sys.argv[1:6])

def divisors(n):
    s = set()
    i = 2
    while i*i <= n:
        if n%i == 0:
            s.add(i)
        i+=1
    s.add(n)
    return s

def win(n, k):
    return 1 if n%(k+1) != 0 else 0

while True:
    if not result:
        n = randint(minN, maxN)
        divs = list(divisors(n))
        k = divs[randint(0, len(divs)-1)]-1
    else:
        n = randint(minN, maxN)
        k = randint(minK, maxK)
    if minN <= n <= maxN and minK <= k <= maxK and win(n,k) == bool(result):
        print(n, k)
        break

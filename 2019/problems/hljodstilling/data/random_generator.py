import sys
import random

# Type of testcase:
#   1: small
#   2: large
tc = int(sys.argv[1])
min_k = int(sys.argv[2])
max_k = int(sys.argv[3])
shuffle = int(sys.argv[4])
if len(sys.argv) > 5:
    random.seed(int(sys.argv[5]))

primes = []
with open("primes.txt") as f:
    for x in f.read().split():
        primes.append(int(x))

if shuffle:
    random.shuffle(primes)

k = random.randint(min_k, max_k)
if tc == 1:
    L = random.randint(1, 10**14)
    R = random.randint(L, L+10000)

    print(L, R, k)
    print(" ".join(str(x) for x in primes[:k]))
elif tc == 2:
    L = random.randint(1, 10**14)
    R = random.randint(L, 10**14)
   
    print(L, R, k)
    print(" ".join(str(x) for x in primes[:k]))

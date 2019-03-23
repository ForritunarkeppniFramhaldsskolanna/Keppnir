import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: Given values
typ  = int(sys.argv[1])
arr = []
n = 0
k = 0

def get(n,mz):
    sol = []
    for x in range(n):
        sol.append(random.randint(1,mz))
    return sol

if typ == 1:
    n = random.randint(5,100)
    k = 1
    arr = get(n,100)
elif typ == 2:
    n = random.randint(5,100)
    k = random.randint(2,100)
    arr = get(n,100)
elif typ == 3:
    n = random.randint(5,10**5)
    k = random.randint(2,10**5)
    arr = get(n,10**9)

print(str(n) + " " + str(k))
arr = sorted(arr)
ok =  []
for x in range(n):
    ok.append(str(arr[x]))
print(' '.join(ok))


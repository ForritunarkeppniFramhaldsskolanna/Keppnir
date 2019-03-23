import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: Given values
typ  = int(sys.argv[1])
n = random.randint(1,1000)
x = random.randint(1,5000)
sol = []

if typ == 1:
    same = random.randint(1,500)
    for x in range(n):
        L = random.randint(1,5000)
        R = random.randint(L,5000)
        sol.append([L,R,same])
elif typ == 2:
    for x in range(n):
        same = random.randint(1,500)
        L = random.randint(1,5000)
        R = random.randint(L,5000)
        sol.append([L,R,same])

print(str(n) + " " + str(x))
for x in range(n):
    print(str(sol[x][0]) + " " + str(sol[x][1]) + " " + str(sol[x][2]))


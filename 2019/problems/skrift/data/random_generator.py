import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: specific
#   4: Given values
tc = int(sys.argv[1])

def split_n_into_m(n, m):
    sm = 0
    arr = []
    for x in range(m-1):
        sz = random.randint(1,n-sm-(m-(x+1)))
        sm += sz
        arr.append(sz)
    arr.append(n-sm)
    return arr

def get_q(n, random_for_q, q):
    sol = []
    if random_for_q == 1:
        arr = split_n_into_m(n,q)
        for x in arr:
            sol.append([1,x])
    else:
        sm = 0
        for x in range(q):
            if x == q-1:
                increment = n-sm
                sm += increment
                sol.append([1,increment])
            elif sm == 0:
                increment = random.randint(1,n-1)
                sm += increment
                sol.append([1,increment])

            elif sm == n-1:
                decrement = random.randint(1,sm)
                sm -= decrement
                sol.append([2,decrement])
            else:
                if random.randint(1,2) == 1:
                    increment = random.randint(1,n-sm-1)
                    sm += increment
                    sol.append([1,increment])
                else:
                    decrement = random.randint(1,sm)
                    sm -= decrement
                    sol.append([2,decrement])
    return sol

n = 0
m = 0
q = 0
random_for_q = 2

if tc == 1:
    n = random.randint(3,10)
    q = random.randint(3,n)
    m = random.randint(3,n)
    random_for_q = 1
elif tc == 2:
    n = random.randint(3,10)
    q = random.randint(3,10)
    m = 1
elif tc == 3:
    n = random.randint(3,20)
    q = random.randint(3,20)
    m = 2
elif tc == 4:
    n = random.randint(3,int(sys.argv[2]))
    q = random.randint(3,int(sys.argv[3]))
    m = random.randint(3,min(10**5,n))

darr = split_n_into_m(n,m)
qarr = get_q(n, random_for_q, q)
print(str(n) + " " + str(m) + " " + str(q))
for x in range(m):
    print(str(darr[x]) + " " + str(random.randint(1,10**4)))
for x in range(q):
    print(str(qarr[x][0]) + " " + str(qarr[x][1]))

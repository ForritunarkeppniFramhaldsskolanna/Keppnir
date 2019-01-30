import sys
from random import randint

minN,maxN,minQ,maxQ,T = map(int, sys.argv[1:6])
n = randint(minN, maxN)
q = randint(minQ, maxQ)

print(str(n) + " " + str(q))
arr = []

if T == 1:
    arr = [1,3]
elif T == 2:
    arr = [1,2,3]
elif T == 3:
    arr = [1,2,3,4]

def make(hi, th):
    if th == 1:
        return "1 " + str(randint(1,hi))
    elif th == 2:
        return "2"
    elif th == 3:
        return "3"
    elif th == 4:
        l = randint(1,hi)
        r = randint(l,hi)
        return "4 " + str(l) + " " + str(r)


for x in range(q):
    print(make(n, arr[randint(1,len(arr)) - 1]))
    

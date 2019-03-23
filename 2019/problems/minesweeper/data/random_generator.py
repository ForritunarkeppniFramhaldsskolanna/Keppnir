import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: Given values

st = int(sys.argv[1])
n = 0
m = 0
k = 0
if st == 1:
    n = random.randint(2,15)
    m = random.randint(2,15)
    k = random.randint(2,n*m)
elif st == 2:
    n = random.randint(2,250)
    m = random.randint(2,250)
    k = random.randint(2,n*m)
elif st == 3:
    n = 250
    m = 250
    k = n*m
arr = []
for x in range(1,n+1):
    for y in range(1,m+1):
        arr.append([x,y])
random.shuffle(arr)
print(str(n) + " " + str(m) + " " + str(k))
for x in range(k):
    print(str(arr[x][0]) + " " + str(arr[x][1]))


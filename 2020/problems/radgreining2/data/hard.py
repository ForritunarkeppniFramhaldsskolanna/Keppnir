import sys
import math
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
m = int(sys.argv[2])
cnt = int(sys.argv[3])

arr = []

if cnt == 2:
    should = random.randint(0,1)
    for i in range(n-1):
        st = random.randint(0,10)
        if st <= 8:
            if should == 0:
                arr.append((i, 'GG'))
            else:
                arr.append((i, 'TT'))
        else:
            arr.append((i, 'GT'))
            should = 1-should

    arr = arr[:m]
elif cnt == 3:
    should = random.randint(0,1)
    at = 0
    while at + 3 - 1 < n:
        st = random.randint(0,10)
        if st <= 8:
            if should == 0:
                arr.append((at, 'GAG'))
            else:
                arr.append((at, 'TAT'))
        else:
            arr.append((at, 'GAT'))
            should = 1-should
        at += 2

    arr = arr[:m]
elif cnt == 15:
    should = random.randint(0,1)
    at = 0
    while at + 15 - 1 < n:
        st = random.randint(0,10)
        if st <= 8:
            if should == 0:
                arr.append((at, 'TTTTTTCAGTTTTTT'))
            else:
                arr.append((at, 'GGGGGGCAGGGGGGG'))
        else:
            arr.append((at, 'TTTTTTCAGGGGGGG'))
            should = 1-should
        at += 9

    arr = arr[:m]

print('%d %d' % (n, len(arr)))
# random.shuffle(arr)
arr = arr[::2] + arr[1::2]
for (i, s) in arr:
    if random.randint(1,2) == 1:
        s = s[::-1]
    print('%d %s' % (i+1, s))


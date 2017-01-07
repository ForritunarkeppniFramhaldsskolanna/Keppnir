import sys
import re
import random
import math

ts = [
    1,
    2,
    3,
    5,
    8,
    10,
    20,
    50,
    100,
    500,
    1000,
    2000,
    3000,
    3000,
    3000,
    3000,
]

def rand():
    return math.floor(random.random() * 400000 - 200000) / 100.0

for t, n in enumerate(ts):

    while True:
        # a = [ rand() for i in range(n + 2) ]

        # a_{i+1} = 2*a_i - a_{i-1} + 2*c_i
        # (a_{i+1} - 2*a_i + a_{i-1})/2 = c_{i-1}

        a = []
        a.append(rand())
        a.append(rand())

        ok = True
        left = 1e4

        c = []
        for i in range(1,n+1):
            while left > 0:
                nxta = rand()
                nxtc = (nxta - 2*a[i] + a[i-1])/2.0
                if -2000-1e-9 <= nxtc <= 2000+1e-9 and abs(nxtc - math.floor(100 * nxtc) / 100.0) < 1e-9:
                    break
                left -= 1
            if left == 0:
                break
            a.append(nxta)
            c.append(nxtc)

        if left == 0:
            continue

        for x in c:
            ok = ok and -2000-1e-9 <= x <= 2000+1e-9

        if ok:

            with open('%02d.in' % t, 'w') as f:
                f.write('%d\n' % n)
                f.write('%0.2f\n' % a[0])
                f.write('%0.2f\n' % a[n+1])

                for x in c:
                    f.write('%0.2f\n' % x)

            with open('%02d.ans' % t, 'w') as f:
                f.write("%0.10f\n" % a[1])

            break


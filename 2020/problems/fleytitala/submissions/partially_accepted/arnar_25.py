#!/usr/bin/python3
d = float(input())
k = int(input())

if k == 0:
    print(d)
elif k == 1:
    print(1.5*d)
elif k == 2:
    print(1.75*d)
elif k == 3:
    print(1.875*d)
elif k == 4:
    print(1.9375*d)
elif k == 5:
    print(1.96875*d)
elif k == 6:
    print(1.984375*d)
elif k == 7:
    print(1.9921875*d)
elif k == 8:
    print(1.99609375*d)
elif k == 9:
    print(1.998046875*d)
else:
    print(1.9990234375*d)

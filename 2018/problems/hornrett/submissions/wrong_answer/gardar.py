import sys
import math
a,b,c = list(map(int, sys.stdin.readline().split(" ")))

if a+b <= c or c+b<=a or a+c<=b:
    print(-1)
    sys.exit(0)

s = (a+b+c) / 2.0
F = int(math.sqrt(s * (s - a) * (s - b) * (s - c)))

if F == a*b:
    print(F/2)
elif F == b*c:
    print(F/2)
elif c*a == F:
    print(F/2)
else:
    print(-1)



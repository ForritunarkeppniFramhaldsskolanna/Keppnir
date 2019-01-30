import sys
line = sys.stdin.readline()
a,b,c = map(int, line.split())
if a**2 + b**2 == c**2:
    sys.stdout.write("%d\n"%(a*b//2))
else:
    sys.stdout.write("-1\n")

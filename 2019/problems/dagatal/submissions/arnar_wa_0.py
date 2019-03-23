import sys
m = int(sys.stdin.readline().rstrip('\n'))
if m == 2:
    print(28)
elif m in [4,6,9,11]:
    print(31)
else:
    print(30)

import sys
d = float(sys.stdin.readline())
k = int(sys.stdin.readline())

print(d * (1 - pow(0.5, k+1)) / (1-0.5))


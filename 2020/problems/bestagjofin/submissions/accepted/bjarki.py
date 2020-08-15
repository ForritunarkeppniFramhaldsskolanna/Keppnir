import sys
n = int(sys.stdin.readline())

arr = []
for i in range(n):
    s = sys.stdin.readline()
    k,v = s.split()
    arr.append((k, int(v)))

arr = sorted(arr, key=lambda k: k[1])
print(arr[-1][0])


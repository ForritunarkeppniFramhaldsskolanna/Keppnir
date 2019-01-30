import sys
n = int(sys.stdin.readline())

curr_min = int(sys.stdin.readline())
for i in range(1,n):
    a = int(sys.stdin.readline())
    if a < curr_min:
        curr_min = a

print(curr_min)

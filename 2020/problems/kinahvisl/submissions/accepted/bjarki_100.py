import sys
a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()

sm = 0
for p,q in zip(a,b):
    if p != q:
        sm += 1

print(sm + 1)


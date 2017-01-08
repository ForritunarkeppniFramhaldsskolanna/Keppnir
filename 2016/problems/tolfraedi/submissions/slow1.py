import sys
Q = int(sys.stdin.readline())
curr = []

for i in range(Q):
    line = sys.stdin.readline().strip().split()
    op, val = line[0], int(line[1])

    if op == 'A':
        curr.append(val)
    else:
        curr.remove(val)

    if len(curr) > 0:
        avg = sum(curr) / len(curr)
    else:
        avg = -1
    mn = -1
    mx = -1
    for i in curr:
        if mn == -1 or i < mn:
            mn = i
        if mx == -1 or i > mx:
            mx = i
    sys.stdout.write("{} {} {}\n".format(mn, mx, avg))

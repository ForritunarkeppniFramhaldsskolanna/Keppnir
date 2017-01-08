import sys
Q = int(sys.stdin.readline())
curr = []

def add(v):
    for i in range(len(curr)):
        if curr[i][0] == v:
            curr[i] = (curr[i][0], curr[i][1]+1)
            return
    curr.append((v,1))

def remove(v):
    for i in range(len(curr)):
        if curr[i][0] == v:
            if curr[i][1] == 1:
                del curr[i]
            else:
                curr[i] = (curr[i][0], curr[i][1]-1)
            return

def total():
    res = 0
    totcnt = 0
    for x,cnt in curr:
        res += x * cnt
        totcnt += cnt
    return (res, totcnt)

for i in range(Q):
    line = sys.stdin.readline().strip().split()
    op, val = line[0], int(line[1])

    if op == 'A':
        add(val)
    else:
        remove(val)

    if len(curr) > 0:
        sm, cnt = total()
        avg = sm / cnt
    else:
        avg = -1

    mn = -1
    mx = -1
    for x,cnt in curr:
        if mn == -1 or x < mn:
            mn = x
        if mx == -1 or x > mx:
            mx = x
    sys.stdout.write("{} {} {}\n".format(mn, mx, avg))

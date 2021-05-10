import sys

n, q = [int(x) for x in sys.stdin.readline().strip().split()]
c = [0 for i in range(n)]

for i in range(q):
    inp = [int(x) for x in sys.stdin.readline().strip().split()]
    if inp[0] == 1:
        c = c[inp[1]:] + c[:inp[1]]
    elif inp[0] == 2:
        p = inp[1] - 1
        while True:
            c[p] += inp[3]
            if p == inp[2] - 1:
                break
            p += 1
            p %= n
    else:
        s, p = 0, inp[1] - 1
        while True:
            s += c[p]
            if p == inp[2] - 1:
                break
            p += 1
            p %= n
        print(s)


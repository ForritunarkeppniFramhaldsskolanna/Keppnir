import sys
n = int(sys.stdin.readline().strip())
ys = map(int, sys.stdin.readline().strip().split())

mod = 1000000007
mem = {}

def cnt(xs):
    if xs == ys:
        return 1
    for x,y in zip(xs,ys):
        if x > y:
            return 0
    if tuple(xs) in mem:
        return mem[tuple(xs)]

    res = sum( cnt([ xs[j]+1 if i == j else xs[j] for j in range(n) ]) for i in range(n) )
    res %= mod
    mem[tuple(xs)] = res
    return res

print(cnt([0]*n))


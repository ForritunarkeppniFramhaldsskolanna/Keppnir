#!/usr/bin/python3

n = int(input())

if n >= 10**18:
    print(2**(len(str(n))-1))
else:

    def gen():
        L = [set([2])]
        for i in range(18):
            L.append(set())
            for x in L[i]:
                L[i+1].add(10*x+0)
                L[i+1].add(10*x+2)
        L[0].add(0)
        ret = []
        for x in L:
            ret.extend(x)
        return ret

    cnt = 0
    for x in gen():
        if x <= n:
            cnt += 1

    print(cnt)

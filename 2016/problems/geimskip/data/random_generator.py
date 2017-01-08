#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys

N = int(sys.argv[1])
M = int(sys.argv[2])
big = int(sys.argv[3])
chain = sys.argv[4]
random.seed(int(sys.argv[5]))

lines = []


if big == 1:
    mn, mx, mxr = -(10**4), 10**4, 10**3
else:
    mn, mx, mxr = -(10**2), 10**2, 10
    if N + M < 110:
        mn, mx = min(-(N + M)//2, -20), max((N + M)//2, 20)


def dist(p0, p1):
    return math.sqrt((p0[0] - p1[0])**2 + (p0[1] - p1[1])**2 + (p0[2] - p1[2])**2)

def gen_wchain():
    sys.stderr.write("wchain\n")
    spaceships = []
    bombs = []
    lines.append(str(N))
    for i in range(N):

        scoll = True
        while scoll:
            scoll = False
            x = random.randint(mn, mx)
            y = random.randint(mn, mx)
            z = random.randint(mn, mx)
            r = random.randint(1, mxr)

            for s in spaceships:
                if dist(s[0], (x,y,z)) <= s[1] + r:
                    scoll = True
                    break

            if not scoll:
                spaceships.append(((x,y,z),r))
                lines.append("{} {} {} {}".format(x,y,z,r))

    lines.append(str(M))
    for j in range(M):

        x = random.randint(mn, mx)
        y = random.randint(mn, mx)
        z = random.randint(mn, mx)
        r = random.randint(1, mxr)

        bombs.append(((x,y,z),r))
        lines.append("{} {} {} {}".format(x,y,z,r))

def gen_nochain():
    sys.stderr.write("nochain\n")
    spaceships = []
    bombs = []
    lines.append(str(N))
    while len(spaceships) < N:
        scoll = False
        willchain = False
        x = random.randint(mn, mx)
        y = random.randint(mn, mx)
        z = random.randint(mn, mx)
        r = random.randint(1, mxr)

        for s in spaceships:
            if dist(s[0], (x,y,z)) <= s[1] + r:
                scoll = True
                break
            if dist(s[0], (x,y,z)) <= max(s[1] + 2*r, 2*s[1] + r):
                willchain = True
                break

            #for j,s in enumerate(spaceships):
                #if dist(s[0], (x,y,z)) <= s[1] + r:
                    #scoll = True
                    #break
                #if dist(s[0], (x,y,z)) <= s[1] + 2*r:
                    #willchain = True
                #if dist(s[0], (x,y,z)) <= 2*s[1] + r:
                    #chain[j] = True

            #if not scoll:
                #spaceships.append(((x,y,z),r))
                #chain[i] = willchain
                #lines.append("{} {} {} {}".format(x,y,z,r))

    #lines.append(str(M))
    #for j in range(M):

        #willchain = True
        #while willchain:
            #willchain = False
            #x = random.randint(mn, mx)
            #y = random.randint(mn, mx)
            #z = random.randint(mn, mx)
            #r = random.randint(1, mxr)

            #for i,s in enumerate(spaceships):
                #if dist(s[0], (x,y,z)) <= s[1] + r and chain[i]:
                    #willchain = True
                    #break

            #if not willchain:
                #bombs.append(((x,y,z),r))
                #lines.append("{} {} {} {}".format(x,y,z,r))
        if not scoll and not willchain:
            spaceships.append(((x,y,z),r))
            lines.append("{} {} {} {}".format(x,y,z,r))

    lines.append(str(M))
    for j in range(M):
        x = random.randint(mn, mx)
        y = random.randint(mn, mx)
        z = random.randint(mn, mx)
        r = random.randint(1, mxr)
        bombs.append(((x,y,z),r))
        lines.append("{} {} {} {}".format(x,y,z,r))

def gen_chainsmall():
    sys.stderr.write("chainsmall\n")
    cnt = 0
    spaceships = []
    bombs = []
    lines.append(str(N))
    for k in range(10):
        if cnt == N:
            break
        for i in range(10):
            if cnt == N:
                break
            for j in range(10):
                if cnt == N:
                    break
                lines.append("{} {} {} {}".format(3 + i*5, 3 + j*5, 3*k, 2))
                cnt += 1
    lines.append(str(M))
    if M > 0:
        lines.append("0 0 0 3")
        cnt = 1
        for k in range(10):
            if cnt == M:
                break
            for i in range(10):
                if cnt == M:
                    break
                for j in range(10):
                    if cnt == M:
                        break
                    lines.append("{} {} {} {}".format(3 + i*5, 3 + j*5, -3*k, 2))
                    cnt += 1

def gen_chainbig():
    sys.stderr.write("chainbig\n")
    cnt = 0
    spaceships = []
    bombs = []
    lines.append(str(N))
    for k in range(10):
        if cnt == N:
            break
        for i in range(10):
            if cnt == N:
                break
            for j in range(10):
                if cnt == N:
                    break
                lines.append("{} {} {} {}".format(300 + i*500, 300 + j*500, 300*k, 200))
                cnt += 1
    lines.append(str(M))
    if M > 0:
        lines.append("0 0 0 300")
        cnt = 1
        for k in range(10):
            if cnt == M:
                break
            for i in range(10):
                if cnt == M:
                    break
                for j in range(10):
                    if cnt == M:
                        break
                    lines.append("{} {} {} {}".format(300 + i*500, 300 + j*500, -300*k, 200))
                    cnt += 1

if chain == 'chain' and big == 0:
    gen_chainsmall()
elif chain == 'chain' and big == 1:
    gen_chainbig()
elif N == 1 or chain == 'nochain':
    gen_nochain()
elif chain == 'wchain':
    gen_wchain()
else:
    assert(False)


print('\n'.join(lines))
#sys.stderr.write('\n'.join(lines))
sys.stderr.write("generated {}, {}\n".format(N, M))
sys.stderr.write("space size [{},{}]^2\n".format(mn, mx))

import sys
import random
import math

N = int(sys.argv[1])
mT = int(sys.argv[2])
method = sys.argv[3]
random.seed(int(sys.argv[4]))

mT -= 1

def random_subdivision(slots, mT):
    if mT <= 10**5:
        picked = [ i for i in range(1,mT+1) ]
        random.shuffle(picked)
        picked = [0] + sorted(picked[:slots-1]) + [mT+1]
    else:
        picked = set()
        picked.add(0)
        picked.add(mT+1)
        while len(picked) < slots+1:
            picked.add(random.randint(1,mT))
        picked = sorted(picked)

    sub = []
    for i in range(slots):
        sub.append((picked[i], picked[i+1]-1))
    return sub

def random_interval(l,r):
    a = random.randint(l,r)
    b = random.randint(l,r)
    if a > b:
        a,b = b,a
    return (a,b)

def random_point(l,r):
    return random.randint(l,r)

def gen_random(N, mT):
    L = [ random.randint(0,mT) for _ in range(N) ]
    H = [ random.randint(0,mT) for _ in range(N) ]
    T = [ random.randint(0,mT) for _ in range(N) ]
    T[0] = mT

    for i in range(N):
        if L[i] > H[i]:
            L[i],H[i] = H[i],L[i]

    return (L,H,T)

def gen_sim_random(N, mT, rand, all=False):
    pq = []
    ints = []
    pts = []
    pos = 0
    while len(ints) < N or len(pts) < N:
        add = int(round(random.expovariate(0.5)))
        for i in range(add):
            ints.append((pos,None))
            pq.append(len(ints)-1)

        rem = int(round(random.expovariate(0.5)))
        if all:
            rem = min(rem, len(pq))
        for i in range(rem):
            if pq:
                at = random.randint(0,len(pq)-1)
                pq[at],pq[-1] = pq[-1],pq[at]
                r = pq.pop()
                ints[r] = (ints[r][0], pos)
            pts.append(pos)

        pos += 1

    ints = [ (a,pos-1 if b is None else b) for (a,b) in ints[:N] ]
    pts = pts[:N]

    assert pos <= mT+1
    # print(pos)
    sub = random_subdivision(pos, mT)
    # print(sub)

    L = [ sub[ints[i][0]][0] for i in range(N) ]
    H = [ sub[ints[i][1]][1] for i in range(N) ]
    if rand:
        T = [ random.randint(0,mT) for i in range(N) ]
    else:
        T = [ random_point(*sub[pts[i]]) for i in range(N) ]

    return (L,H,T)

def gen_biased(N, mT, to):

    L = []
    H = []
    T = []
    for i in range(N):
        if random.randint(0,1) == 0:
            L.append(1-to)
            H.append(1-to)
        elif random.randint(0,1) == 0:
            L.append(0)
            H.append(1)
        else:
            L.append(to)
            H.append(to)

        if random.randint(0,2) <= 1:
            T.append(to)
        else:
            T.append(1-to)

    return (L,H,T)

def gen_none(N, mT):
    assert 2*N <= (mT+1)

    sub = random_subdivision(2*N, mT)
    random.shuffle(sub)

    for i in range(len(sub)):
        if sub[i][1] == mT:
            sub[i], sub[-1] = sub[-1], sub[i]
            break

    ints = [ random_interval(*sub[i]) for i in range(N) ]
    pts = [ random_point(*sub[N+i]) for i in range(N) ]

    L = [ ints[i][0] for i in range(N) ]
    H = [ ints[i][1] for i in range(N) ]
    T = pts
    return (L,H,T)

def gen_all_unique(N, mT):
    assert N <= (mT+1)

    c = 1
    while (c+1) <= 10 and (c+1)*N <= mT:
        c += 1

    sub = random_subdivision(c*N, mT)
    random.shuffle(sub)

    sub = [ (sub[i][0], sub[i][1], i if i < N else -1) for i in range(len(sub)) ]
    sub = sorted(sub)

    prev = [None] * len(sub)
    nxt = [None] * len(sub)

    p = -1
    for i in range(len(sub)):
        prev[i] = p
        if sub[i][2] != -1:
            p = i
    p = len(sub)
    for i in range(len(sub)-1,-1,-1):
        nxt[i] = p
        if sub[i][2] != -1:
            p = i

    L = [None] * N
    H = [None] * N
    T = [None] * N
    at = 0
    for i in range(len(sub)):
        if sub[i][2] != -1:
            T[at] = random_point(sub[i][0], sub[i][1])
            L[at] = 0 if prev[i] == -1 else sub[prev[i]][1]+1
            H[at] = mT if nxt[i] == len(sub) else sub[nxt[i]][0]-1
            at += 1

    T[-1] = H[-1]

    return (L,H,T)

def gen_dense(N, mT):
    assert (mT+1)*(mT+2)//2 >= N
    ints = []
    l = mT
    left = 0
    while len(ints) < N:
        if left+l-1 >= mT:
            l -= 1
            left = 0
        assert l >= 1
        ints.append((left, left + l - 1))
        left += 1

    L = [ ints[i][0] for i in range(N) ]
    H = [ ints[i][1] for i in range(N) ]

    l = mT//2
    r = mT//2+1
    T = []
    while len(T) < N:
        if l >= 0:
            T.append(l)
            l -= 1
        if len(T) < N and r <= mT:
            T.append(r)
            r += 1
        if len(T) < N and l < 0 and r > mT:
            T.append(mT//2)

    T[0] = mT
    return (L,H,T)

def shuffle_data(L,H,mT):
    ints = [ (L[i],H[i]) for i in range(len(L)) ]
    random.shuffle(ints)
    random.shuffle(T)
    for i in range(len(ints)):
        L[i] = ints[i][0]
        H[i] = ints[i][1]

if method == 'random':
    (L,H,T) = gen_random(N, mT)
elif method == 'sim_random':
    (L,H,T) = gen_sim_random(N, mT, False)
elif method == 'sim_random2':
    (L,H,T) = gen_sim_random(N, mT, True)
elif method == 'sim_random_all':
    (L,H,T) = gen_sim_random(N, mT, False, True)
elif method == 'none':
    (L,H,T) = gen_none(N, mT)
elif method == 'all_unique':
    (L,H,T) = gen_all_unique(N, mT)
elif method == 'dense':
    (L,H,T) = gen_dense(N, mT)
elif method == 'biased0':
    (L,H,T) = gen_biased(N, mT, 0)
elif method == 'biased1':
    (L,H,T) = gen_biased(N, mT, 1)
else:
    assert False

shuffle_data(L,H,T)

assert len(L) == len(H)
assert len(L) == len(T)
sys.stdout.write('%d\n' % len(L))
for i in range(len(L)):
    sys.stdout.write('%d %d\n' % (L[i]+1, H[i]+1))
sys.stdout.write('%s\n' % ' '.join([ str(x+1) for x in T ]))


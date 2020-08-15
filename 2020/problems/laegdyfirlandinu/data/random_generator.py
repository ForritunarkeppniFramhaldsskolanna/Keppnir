import sys
import random
sys.setrecursionlimit(10**9)

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
m = eval(sys.argv[2])
method = sys.argv[3]

if method == 'random':
    arr = [[random.randint(1,10**9) for j in range(m)] for i in range(n)]
else:

    arr = [[None for j in range(m)] for i in range(n)]

    def is_bad(i,j):
        if not (0 <= i < n and 0 <= j < m):
            return False
        if arr[i][j] is None:
            return False

        for di in range(-1,2):
            for dj in range(-1,2):
                if abs(di) + abs(dj) != 1:
                    continue
                ni = i + di
                nj = j + dj
                if not (0 <= ni < n and 0 <= nj < m):
                    return False
                if arr[ni][nj] is None or arr[ni][nj] <= arr[i][j]:
                    return False

        return True

    def bt(x,y):
        if y == m:
            return bt(x+1, 0)
        if x == n:
            return True

        found = set()
        for di in range(-1,2):
            for dj in range(-1,2):
                if abs(di) + abs(dj) != 1:
                    continue

                i = x + di
                j = y + dj
                if 0 <= i < n and 0 <= j < m and (i,j) < (x,y):
                    found.add(arr[i][j])

        found = list(sorted(found))
        ranges = []
        # for f in found:
        #     ranges.append((f,f))
        ranges.append((found[0]-1,found[0]-1))
        ranges.append((found[-1]+1,found[-1]+1))
        for (a,b) in zip(found, found[1:]):
            if a + 1 < b:
                ranges.append((a+1,b-1))

        random.shuffle(ranges)
        for r in ranges:
            cur = random.randint(r[0],r[1])
            arr[x][y] = cur
            if is_bad(x,y):
                print(x, y, arr, x, y)
                continue
            ok = True
            for di2 in range(-1,2):
                for dj2 in range(-1,2):
                    if abs(di2) + abs(dj2) != 1:
                        continue
                    if is_bad(x+di2, y+dj2):
                        ok = False
                        # print(x, y, arr, x+di2, y+dj2)
            if ok and bt(x,y+1):
                return True
        arr[x][y] = None
        return False

    arr[0][0] = 0
    while True:
        if bt(0,1):
            break
        break

    mn = min(col for row in arr for col in row )
    for i in range(n):
        for j in range(m):
            arr[i][j] -= mn - 1

    if method == 'almost':
        mn = min(col for row in arr for col in row )
        mx = max(col for row in arr for col in row )
        arr[random.randint(1,n-2)][random.randint(1,m-2)] = random.randint(max(mn-1,1),mx+1)

sys.stdout.write('%d %d\n' % (n,m))
for row in arr:
    sys.stdout.write('%s\n' % ' '.join(map(str, row)))


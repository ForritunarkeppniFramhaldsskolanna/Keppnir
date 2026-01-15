def myfloat(x):
    if x == "-":
        return 0.0
    else:
        return float(x)


n, m = map(int, input().strip().split())
_ = input()
inps = [list(map(myfloat, input().strip().split())) for _ in range(n)]
avgs = [0, 0, 0, 0]
for j in range(n - m, n):
    for k in range(4):
        avgs[k] += inps[j][k]
for k in range(4):
    avgs[k] /= m
for _ in range(m):
    print(*avgs)

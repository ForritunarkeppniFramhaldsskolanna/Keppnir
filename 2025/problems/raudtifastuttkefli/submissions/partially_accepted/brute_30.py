n, k = map(int, input().strip().split())
ld = [tuple(map(int, input().strip().split())) for _ in range(n)]
t = int(input())
best = 0
for mask in range(1 << n):
    dop, tim = 0, 0
    for i in range(n):
        if mask & (1 << i):
            tim += ld[i][0]
            dop += ld[i][1]
        else:
            tim += k
    for i in range(n - 1, -1, -1):
        if mask & (1 << i):
            break
        tim -= k
    if tim <= t:
        best = max(best, dop)
print(best)

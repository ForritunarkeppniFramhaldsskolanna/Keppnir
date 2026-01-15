n, k = map(int, input().strip().split())
ld = [tuple(map(int, input().strip().split())) for _ in range(n)]
t = int(input())
dop = 0
for i in range(n):
    t -= ld[i][0]
    if t < 0:
        break
    dop += ld[i][1]
print(dop)

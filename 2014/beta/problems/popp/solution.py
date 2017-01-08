n = int(input())
pop = [ None ]*n

for i in range(n):
    pop[i] = tuple(list(map(int, input().split())))

rt = 0
rc = 0

for t in range(3000):
    cnt = 0
    for i in range(n):
        if pop[i][0] <= t <= pop[i][0] + pop[i][1] - 1:
            cnt += 1

    if cnt > rc:
        rc = cnt
        rt = t

print("%d %d\n" % (rt, rc))


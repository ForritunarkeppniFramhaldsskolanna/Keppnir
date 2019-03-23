import sys
n = int(sys.stdin.readline().rstrip('\n'))
arr = list(map(int, sys.stdin.readline().rstrip('\n').split()))

best = [1 for i in range(n)]
for i in range(n):
    for j in range(i):
        if arr[j] > arr[i]:
            best[i] = max([best[i], best[j]+1])

sys.stdout.write("%d\n" % max(best))

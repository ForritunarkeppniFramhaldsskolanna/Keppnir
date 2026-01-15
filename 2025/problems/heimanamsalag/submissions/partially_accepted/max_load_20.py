from collections import Counter

work = Counter()
n = int(input())
if n == 0:
    print(0)
else:
    for i in range(n):
        inp = tuple(map(int, input().strip().split()))
        work[inp[0]] += inp[2]
    print(max(work.values()))

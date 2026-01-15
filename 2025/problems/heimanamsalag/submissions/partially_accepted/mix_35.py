from collections import Counter

work = Counter()
n = int(input())
if n == 0:
    print(0)
elif n == 1:
    a, b, t = map(int, input().strip().split())
    days = b - a + 1
    print((t + days - 1) // days)
else:
    for i in range(n):
        inp = tuple(map(int, input().strip().split()))
        work[inp[0]] += inp[2]
    print(max(work.values()))

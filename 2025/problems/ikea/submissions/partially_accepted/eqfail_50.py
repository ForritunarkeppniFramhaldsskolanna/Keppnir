k = int(input())
n = int(input())
inp = [tuple(input().strip().split()) for _ in range(n)]
inp.sort(key=lambda x: int(x[1]))
ch = inp[: n // k]
if n % k != 0:
    alt = inp[: n // k + 1]
    nxt = inp[n // k + 1 : n // k + n // k + 1]
    if sum(int(x[1]) for x in alt) <= sum(int(x[1]) for x in nxt):
        ch = alt
print(sum(int(x[1]) for x in ch))
ch.sort()
for c in ch:
    print(c[0])

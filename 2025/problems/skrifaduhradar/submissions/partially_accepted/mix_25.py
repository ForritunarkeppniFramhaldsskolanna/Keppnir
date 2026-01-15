n, t = map(int, input().strip().split())
w = list(map(int, input().strip().split()))
if t == 1:
    print(sum(w) + 1)
    exit(0)
tst = max(w[0] // t, 1)
while w[0] // tst >= t:
    tst += 1
print(tst)

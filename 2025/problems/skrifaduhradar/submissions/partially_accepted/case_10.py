n, t = map(int, input().strip().split())
w = int(input())
tst = max(w // t, 1)
while w // tst >= t:
    tst += 1
print(tst)

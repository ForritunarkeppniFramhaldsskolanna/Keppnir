n, t = map(int, input().strip().split())
w = sorted(list(map(int, input().strip().split())))
tst = 1
while True:
    written, penalty = 0, 0
    for wi in w:
        written += wi
        penalty += written // tst
    if penalty < t:
        break
    tst += 1
print(tst)

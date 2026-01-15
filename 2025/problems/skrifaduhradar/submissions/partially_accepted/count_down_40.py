n, t = map(int, input().strip().split())
w = sorted(list(map(int, input().strip().split())))
tst = sum(w) + 2
while True:
    written, penalty = 0, 0
    for wi in w:
        written += wi
        penalty += written // tst
    if penalty >= t:
        print(tst + 1)
        break
    tst -= 1
    if tst == 0:
        print(1)
        break

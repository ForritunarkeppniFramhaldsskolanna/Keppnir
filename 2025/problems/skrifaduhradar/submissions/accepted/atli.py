n, T = map(int, input().strip().split())
w = sorted(list(map(int, input().strip().split())))
lo, hi = 1, sum(w) + 1
while lo < hi:
    md = lo + (hi - lo) // 2
    cur_t, left, sm = 0, md - 1, 0
    for wi in w:
        if left >= wi:
            left -= wi
        else:
            wi -= left + 1
            cur_t += 1 + (wi // md)
            wi %= md
            left = md - 1 - wi
        sm += cur_t
    if sm >= T:
        lo = md + 1
    else:
        hi = md
print(lo)

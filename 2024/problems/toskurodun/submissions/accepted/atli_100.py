#!/usr/bin/python3
n, m = map(int, input().strip().split())
ka, kb = map(int, input().strip().split())
kis = [] if m == 0 else list(map(int, input().strip().split()))
kis = [min(n, x) for x in [ka] + kis + [kb]]
cur_ind = 0
for k in kis[::-1]:
    if k == n:
        continue
    if cur_ind // k == n // k:
        cur_ind = cur_ind + (n % k) - 1 - 2 * (cur_ind % k)
    else:
        cur_ind = cur_ind + k - 1 - 2 * (cur_ind % k)
    cur_ind = n - 1 - cur_ind
print(cur_ind + 1)

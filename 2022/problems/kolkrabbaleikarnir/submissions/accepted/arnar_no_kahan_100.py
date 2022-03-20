#!/usr/bin/python3
import math
n, m = map(int, input().split())

fac_lg = [0 for _ in range(n+1)]
for i in range(1, n+1):
    fac_lg[i] = fac_lg[i-1] + math.log(i)

result = 0.0
for i in range(min(n, m)+1):
    n_choose_i_lg = fac_lg[n] - fac_lg[n-i] - fac_lg[i]
    two_to_n_lg = n * math.log(2)
    paths = math.exp(n_choose_i_lg - two_to_n_lg)
    result += paths * (m - i)
print("{:.16f}".format(result))

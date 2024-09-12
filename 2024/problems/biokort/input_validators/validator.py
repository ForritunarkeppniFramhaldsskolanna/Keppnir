#!/usr/bin/python3

import re, sys

INF = float('inf')
min_n = 1
max_n = -INF
min_m = 0
max_m = -INF
min_k = 0
max_k = -INF
min_popularity = 0
max_popularity = -1
min_distinct = 1
max_distinct = 0

for arg in sys.argv[1:]:
    exec(arg)

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* (0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
n, m, k = map(int, line.split())

assert min_n <= n <= max_n, f"{min_n} <= {n} <= {max_n}"
assert min_m <= m <= max_m, f"{min_m} <= {m} <= {max_m}"
assert min_k <= k <= max_k, f"{min_k} <= {k} <= {max_k}"

names = set()
popularities = set()

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[A-Za-z0-9]+ (0|[1-9][0-9]*)\n$", line)
    name, popularity = line.split()
    popularity = int(popularity)
    assert 1 <= len(name) <= 20
    assert min_popularity <= popularity <= max_popularity
    assert name not in names
    names.add(name)
    popularities.add(popularity)

assert min_distinct <= len(popularities) <= max_distinct
assert not sys.stdin.read()
sys.exit(42)

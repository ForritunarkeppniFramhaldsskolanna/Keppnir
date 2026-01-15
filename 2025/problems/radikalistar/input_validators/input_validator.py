#!/usr/bin/python3
import sys
import re

max_n = 10000000
max_q = 1000000
max_m = 1000000

exec(sys.argv[1])  # max_n
exec(sys.argv[2])  # max_q
exec(sys.argv[3])  # max_m

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)
n, q = map(int, line.strip().split())

assert 1 <= n <= max_n
assert 1 <= q <= max_q

MAX_IO = 2 * 10**6

input_left = MAX_IO - 2
output_left = MAX_IO

locs = list(range(n))
ord_elem = list(range(n))
sent = [-1 for _ in range(n)]
set_ind = [0 for _ in range(n)]
ranges = [(0, n - 1)]
reuse = []
nonz = 1

for _ in range(q):
    line = sys.stdin.readline()
    assert line[0] in ["r", "m", "s"]
    args = line.strip().split()
    if args[0] == "r":
        assert re.match("^r [1-9][0-9]* [1-9][0-9]*( [1-9][0-9]*)*\n$", line)
        m = int(args[1])
        assert 1 <= m <= max_m
        assert len(args) == m + 2
        input_left -= m + 1
        to_fix = []
        for arg in args[2:]:
            assert 1 <= int(arg) <= n
            it = int(arg) - 1
            ind = set_ind[it]
            sz = ranges[ind][1] - ranges[ind][0] + 1
            if sz == 1 and sent[ind] == -1:
                continue
            if sent[ind] == -1:
                to_fix.append(ind)
                new_ind = len(ranges)
                nonz += 1
                if len(reuse) > 0:
                    new_ind = reuse[-1]
                    reuse.pop()
                else:
                    ranges.append((-1, -1))
                ranges[new_ind] = (ranges[ind][1] + 1, ranges[ind][1])
                sent[ind] = new_ind
            ranges[sent[ind]] = (ranges[sent[ind]][0] - 1, ranges[sent[ind]][1])
            ranges[ind] = (ranges[ind][0], ranges[ind][1] - 1)
            if ranges[ind][1] < ranges[ind][0]:
                reuse.append(ind)
                nonz -= 1
            to_swp = ord_elem[ranges[sent[ind]][0]]
            locs[it], locs[to_swp] = locs[to_swp], locs[it]
            ord_elem[locs[it]], ord_elem[locs[to_swp]] = ord_elem[locs[to_swp]], ord_elem[locs[it]]
            set_ind[it] = sent[ind]
        for x in to_fix:
            sent[x] = -1
    elif args[0] == "s":
        assert re.match("^s\n$", line)
        output_left -= 1
    else:
        assert re.match("^m [1-9][0-9]*\n$", line)
        assert 1 <= int(args[1]) <= n
        x = int(args[1]) - 1
        input_left -= 1
        s = set_ind[x]
        to_print = list(str(ord_elem[y] + 1) for y in range(ranges[s][0], ranges[s][1] + 1))
        output_left -= len(to_print)

assert input_left >= 0
assert output_left >= 0

assert not sys.stdin.read()
sys.exit(42)

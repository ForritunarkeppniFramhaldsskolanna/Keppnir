#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # max_n
exec(sys.argv[2]) # max_q
exec(sys.argv[3]) # par
exec(sys.argv[4]) # ties

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)
n, q = map(int, line.strip().split())
assert 1 <= n <= max_n
assert 1 <= q <= max_q

total_letters = 0

line = sys.stdin.readline()
assert re.match("^[a-zA-Z]+( [a-zA-Z]+)*\n$", line)
name_list = line.strip().split()
assert len(name_list) == n
assert len(set(name_list)) == n
for name in name_list:
    assert 1 <= len(name) <= 20

names = dict()
for i in range(n):
    names[name_list[i]] = i

scores = [0 for _ in range(n)]
with_score = dict()
with_score[0] = set(range(n))

for _ in range(q):
    line = sys.stdin.readline()
    assert line[0] in ['!', '?']
    if line[0] == '!':
        assert not par
        assert re.match("^! [1-9][0-9]*( [a-zA-Z]+ -?[1-9][0-9]*)*\n$", line)
        dat = line.strip().split()
        assert len(dat) == 2 * int(dat[1]) + 2
        seen_now = set()
        for k in range(2, len(dat), 2):
            assert dat[k] in names
            assert dat[k] not in seen_now
            total_letters += len(dat[k])
            seen_now.add(dat[k])
            assert -10 ** 9 <= int(dat[k + 1]) <= 10 ** 9
            ind = names[dat[k]]
            with_score[scores[ind]].remove(ind)
            scores[ind] += int(dat[k + 1])
            if scores[ind] not in with_score:
                with_score[scores[ind]] = set()
            with_score[scores[ind]].add(ind)
    else:
        assert re.match("^\? [a-zA-Z]+\n$", line)
        name = line[1:].strip()
        assert name in names
        total_letters += len(name)
        if not ties:
            assert len(with_score[scores[names[name]]]) == 1

assert not sys.stdin.readlines()
sys.exit(42)


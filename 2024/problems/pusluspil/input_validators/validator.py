#!/usr/bin/env python3

import re
import sys

min_n = float('inf')
max_n = float('-inf')
min_m = float('inf')
max_m = float('-inf')
min_nm = float('inf')
max_nm = float('-inf')

for arg in sys.argv[1:]:
    exec(arg)

line = sys.stdin.readline()
assert re.match("^[0-9][0-9]* [0-9][0-9]*\n$", line), f"{line}"

n, m = map(int, line.split())

assert min_n <= n <= max_n, f"{min_n} {n} {max_n}"
assert min_m <= m <= max_m, f"{min_m} {m} {max_m}"
assert min_nm <= n * m <= max_nm, f"{min_nm} {n * m} {max_nm}"

for line_org in sys.stdin:
    line = list(line_org.split())

    count = int(line[0])
    assert str(count) == line[0]
    box = line[1:]
    assert len(box) == count, f"{len(box)} {count}, {box}" if len(box) < 20 else f"{len(box)} {count}"
    for item in box:
        assert item == str(int(item)), repr(item)
        assert 1 <= int(item) <= m, repr(item)
    
    assert line_org[-1] == "\n"


assert not sys.stdin.read()
exit(42)


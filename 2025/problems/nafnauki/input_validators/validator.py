#!/usr/bin/python3

import re
import sys

minlen = 1
maxlen = 5
onedot = False

exec(sys.argv[1])  # minlen
exec(sys.argv[2])  # maxlen
exec(sys.argv[3])  # onedot

line = sys.stdin.readline()
assert re.match("^[a-zA-Z0-9\.]+\n$", line)
assert len(line.strip()) <= 32
assert "." in line
if onedot:
    assert line.count(".") == 1
end_len = len(line.strip().split(".")[-1])
assert minlen <= end_len <= maxlen
assert not sys.stdin.read()
sys.exit(42)

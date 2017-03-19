import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line.strip())

s = sys.stdin.readline()
assert re.match('^[HA]+\n$', s)
s = s.strip()
assert len(s) <= 10 * n

at = 0
a = 0
b = 0
while True:
    acur = 0
    bcur = 0
    while True:
        assert at < len(s)
        if s[at] == 'A':
            acur += 1
        elif s[at] == 'H':
            bcur += 1
        else:
            assert False
        at += 1
        if acur == 3:
            a += 1
            break
        if bcur == 3:
            b += 1
            break
    if a == n or b == n:
        break

assert at == len(s)
assert sys.stdin.read() == ''
sys.exit(42)


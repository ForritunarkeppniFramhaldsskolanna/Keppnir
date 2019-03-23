import sys
import re

line = sys.stdin.readline()
assert line == '2500\n'
for i in range(2500):
    line = sys.stdin.readline()
    assert re.match('^[0-9a-f]{32}\n$', line)

assert not sys.stdin.read()
sys.exit(42)

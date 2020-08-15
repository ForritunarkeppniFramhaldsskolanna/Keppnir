import sys
import re

line = sys.stdin.readline()
assert re.match('^[a-zA-Z]*\n$', line)
assert line[-1] == '\n'
line = line[:-1]
n = len(line)
assert 1 <= n <= 10**6
assert not sys.stdin.read()
sys.exit(42)

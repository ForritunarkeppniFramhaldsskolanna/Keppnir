import sys
import re

line = sys.stdin.readline()
assert re.match('^[a-z]+\n$', line)
line = line.strip()
assert 1 <= len(line) <= 10**3

line = sys.stdin.readline()
assert re.match('^[a-z]+\n$', line)
line = line.strip()
assert 1 <= len(line) <= 10**3

assert not sys.stdin.read()
sys.exit(42)


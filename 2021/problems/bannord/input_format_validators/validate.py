import sys
import re

line = sys.stdin.readline()
assert re.match('^[a-z]+\n$', line)
line = line.strip()
assert len(line) == len(set(line))

line = sys.stdin.readline()
assert re.match('^[a-z]+( [a-z]+)*\n$', line)
line = line.strip()
assert len(line) <= 10**5

assert not sys.stdin.read()
sys.exit(42)


import sys
import re

line = sys.stdin.readline()
assert re.match('^u*\n$', line)
assert 1 <= len(line.strip()) <= 1000000

assert not sys.stdin.read()
sys.exit(42)

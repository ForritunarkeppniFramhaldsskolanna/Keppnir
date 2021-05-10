import sys
import re

line = sys.stdin.readline()
assert re.match('^[><-]*\n$', line)
assert 1 <= len(line) - 1 <= 10**6

assert not sys.stdin.read()
sys.exit(42)

import sys
import re

line = sys.stdin.readline()
assert re.match('^[A-Z]\n$', line)

assert not sys.stdin.read()
sys.exit(42)

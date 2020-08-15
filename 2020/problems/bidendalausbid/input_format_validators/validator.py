import sys
import re

line = sys.stdin.readline()
assert re.match('^([0-1][0-9]|2[0-3])\:[0-5][0-9]\n$', line)
line = sys.stdin.readline()
assert re.match('^([0-1][0-9]|2[0-3])\:[0-5][0-9]\n$', line)

assert not sys.stdin.read()
sys.exit(42)

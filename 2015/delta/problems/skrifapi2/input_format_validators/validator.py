import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-9]+\n$', line)
assert 1 <= int(line.strip()) <= 100

assert sys.stdin.read() == ''

sys.exit(42)

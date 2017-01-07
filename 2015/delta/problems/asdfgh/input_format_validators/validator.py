import sys
import re

n = sys.stdin.readline()
assert re.match('[a-z0-9]+\n$', n)

assert sys.stdin.read() == ''

sys.exit(42)

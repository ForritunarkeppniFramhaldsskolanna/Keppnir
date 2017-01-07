import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+(\\.[0-9]+)?\n$', n)
assert sys.stdin.read() == ''

sys.exit(42)

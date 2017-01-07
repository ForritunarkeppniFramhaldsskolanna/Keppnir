import sys
import re

n = sys.stdin.readline()

assert re.match('\d+\n$', n)

assert sys.stdin.read() == ''

sys.exit(42)

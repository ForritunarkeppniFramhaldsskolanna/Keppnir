import sys
import re

line = sys.stdin.readline()
assert re.match('^[a-z]{1,1000}\n$', line)

assert sys.stdin.read() == ''
sys.exit(42)

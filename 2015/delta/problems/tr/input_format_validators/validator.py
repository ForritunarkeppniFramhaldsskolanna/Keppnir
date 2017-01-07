import sys
import re

line = sys.stdin.readline()
assert re.match('^(t [a-zA-Z0-9] [a-zA-Z0-9])|(d [a-zA-Z0-9])\n$', line)
sys.stdin.readline()

assert sys.stdin.read() == ''
sys.exit(42)

import sys
import re

line = sys.stdin.readline()
assert re.match('^[pogPOG.]{1,1000000}\n$', line)
assert line[-1] == '\n'

assert not sys.stdin.read()
sys.exit(42)

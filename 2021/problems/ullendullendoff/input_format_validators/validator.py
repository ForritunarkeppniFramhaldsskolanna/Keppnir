import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)

line = sys.stdin.readline()
assert re.match('^[A-Za-z]{1,10}( [A-Za-z]{1,10}){' + str(n-1) + "," + str(n-1) + '}\n$', line)

assert not sys.stdin.read()
sys.exit(42)

import sys
import re

found = False
for i in range(8):
    line = sys.stdin.readline()
    for j in range(8):
        c = line[j]

        if (i == 0 or i == 7) and (j == 0 or j == 7):
            assert c == '+'
        elif i == 0 or i == 7:
            assert c == '-'
        elif j == 0 or j == 7:
            assert c == '|'
        elif c in {'>','v','<','^'}:
            assert not found
            found = True
        elif c in {'/','\\'}:
            pass
        elif c == '.':
            pass
        else:
            assert False

assert sys.stdin.read() == ''
sys.exit(42)

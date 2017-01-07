import sys
import re

line = sys.stdin.readline()

def validate(s):
    if s == '': return ''
    tag = s.split('+')[0].split('>')[0]
    tlen = len(tag)
    op = s[len(tag):len(tag)+1]
    assert op == '>' or op == '+' or op == ''
    validate(s[tlen+1:])
    splt = tag.split('*')
    tag = splt[0]
    if len(splt) > 1:
        assert len(splt) == 2
        assert splt[1].isdigit()

validate(line.rstrip())

assert sys.stdin.read() == ''

sys.exit(42)

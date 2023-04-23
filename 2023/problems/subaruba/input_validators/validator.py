#!/usr/bin/python3
import sys
import re

VOWELS = ['A', 'Á', 'E', 'É', 'I', 'Í', 'O', 'Ó', 'U', 'Ú', 'Y', 'Ý', 'Æ', 'Ö']
KEY = "ub"

line = sys.stdin.readline()
assert re.match('^[AD]*\n$', line)
should_decode = (line == "A\n")

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)

def encrypt(s):
    res = []
    for c in s:
        if c.upper() in VOWELS:
            res.append(KEY.capitalize() if c.upper() == c else KEY)
            c = c.lower()
        res.append(c)
    return ''.join(res)

def decrypt(s):
    i = 0
    res = []
    while i < len(s):
        big = False
        if s[i:i+2].lower() == KEY:
            if s[i] == KEY[0].upper():
                big = True
            i += 2
        res.append(s[i].upper() if big else s[i])
        i += 1
    return ''.join(res)

s = sys.stdin.read()
assert s[-2] != '\n'
assert s[-1] == '\n'
if should_decode:
    assert encrypt(decrypt(s)) == s
    i = 0
    while i < len(s):
        if s[i].lower() == KEY:
            i += 2
            assert i < len(s)
            assert s[i].upper() in VOWELS
        i += 1

assert decrypt(encrypt(s)) == s

assert not sys.stdin.read()
sys.exit(42)

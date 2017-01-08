#!/usr/bin/env python

import re
import sys

# INNTAK = re.compile('^INNTAK ([a-z0-9]+) (SATT|OSATT|\\?)\n$')
INNTAK = re.compile('^INNTAK ([a-z0-9]+) (SATT|OSATT)\n$')
UTTAK = re.compile('^UTTAK ([a-z0-9]+)\n$')
OG = re.compile('^OG ([a-z0-9]+) ([a-z0-9]+) ([a-z0-9]+)\n$')
EDA = re.compile('^EDA ([a-z0-9]+) ([a-z0-9]+) ([a-z0-9]+)\n$')
EKKI = re.compile('^EKKI ([a-z0-9]+) ([a-z0-9]+)\n$')

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 100000

qcnt = 0
vals = set()
for i in range(n):
    line = sys.stdin.readline()
    if INNTAK.match(line):
        m = INNTAK.match(line)
        inp = m.group(1)
        assert inp not in vals
        vals.add(inp)
        if m.group(2) == '?':
            qcnt += 1
    elif UTTAK.match(line):
        outp = UTTAK.match(line).group(1)
        assert outp in vals
    elif OG.match(line):
        m = OG.match(line)
        a = m.group(1)
        b = m.group(2)
        c = m.group(3)
        assert a in vals
        assert b in vals
        assert c not in vals
        vals.add(c)
    elif EDA.match(line):
        m = EDA.match(line)
        a = m.group(1)
        b = m.group(2)
        c = m.group(3)
        assert a in vals
        assert b in vals
        assert c not in vals
        vals.add(c)
    elif EKKI.match(line):
        m = EKKI.match(line)
        a = m.group(1)
        c = m.group(2)
        assert a in vals
        assert c not in vals
        vals.add(c)
    else:
        assert False

assert qcnt <= 5

assert sys.stdin.read() == ''
sys.exit(42)

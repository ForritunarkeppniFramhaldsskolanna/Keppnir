#!/usr/bin/env python3

import re, sys, ipaddress

exec(sys.argv[1]) # max_q
exec(sys.argv[2]) # v4zeroes
exec(sys.argv[3]) # v6

def check_ip(x):
    if v4zeroes > 0:
        pref = "1" + ("0." * v4zeroes)
        assert x[:len(pref)] == pref
    if '.' in x:
        a = ipaddress.IPv4Address(x)
        return int(a)
    else:
        assert v6
        a = ipaddress.IPv6Address(x)
        return int(a)

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
q = int(line)
assert 1 <= q <= max_q

props = set()
output_len = 0

for _ in range(q):
    line = sys.stdin.readline()
    assert line[0] in ['+', '-', '=', '?']
    if line[0] == '+':
        assert re.match("^\+ [a-zA-Z0-9\-_]+ [a-zA-Z0-9\-_]+\n$", line)
        k, v = line[1:].strip().split()
        props.add(k)
        assert 1 <= len(k) <= 10
        assert 1 <= len(v) <= 10
    if line[0] == '-':
        assert re.match("^- [a-zA-Z0-9\-_]+\n$", line)
        k = line[1:].strip()
        props.remove(k)
        assert 1 <= len(k) <= 10
    if line[0] == '=':
        assert re.match("^= [0-9a-f.:]+ [0-9a-f.:]+ [a-zA-Z0-9\-_]+ [a-zA-Z0-9\-_]+\n$", line)
        a, b, k, v = line[1:].strip().split()
        ipa = check_ip(a)
        ipb = check_ip(b)
        assert ipa <= ipb
        assert 1 <= len(k) <= 10
        assert 1 <= len(v) <= 10
        assert k in props
    if line[0] == "?":
        assert re.match("^\? [0-9a-f.:]+\n$", line)
        a = line[1:].strip()
        check_ip(a)
        output_len += len(props)

assert output_len <= 300000
assert not sys.stdin.readline()
sys.exit(42)

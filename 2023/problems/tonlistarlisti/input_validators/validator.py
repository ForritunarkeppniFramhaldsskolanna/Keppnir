#!/usr/bin/python3
# ctd takes care of formatting
# only checking that playlist is not empty in p queries
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
q = int(line)
assert 1 <= q <= 5 * 10 ** 5
songnamelen = 0
playlist = set()

for i in range(q):
    inp = sys.stdin.readline()
    assert inp[0] in ['P', 'L', 'Q']
    if inp[0] == 'P':
        assert playlist
        assert re.match('^P [1-9][0-9]*\n$', inp)
        t = int(inp.split()[1])
        assert 1 <= t <= 10 ** 9
    if inp[0] == 'L':
        assert re.match('^L [a-z_]+ [1-9][0-9]*\n$', inp)
        _, song, ln = inp.split()
        songnamelen += len(song)
        if song in playlist:
            playlist.remove(song)
        else:
            playlist.add(song)
        ln = int(ln)
        assert 1 <= ln <= 10 ** 3
    if inp[0] == 'Q':
        assert re.match('^Q [a-z_]+\n$', inp)
        _, song = inp.split()
        songnamelen += len(song)

assert songnamelen <= 2 * 10 ** 6
assert not sys.stdin.read()
sys.exit(42)

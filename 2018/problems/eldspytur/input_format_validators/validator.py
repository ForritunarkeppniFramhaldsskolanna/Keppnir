import sys
line = sys.stdin.readline().rstrip('\n')
splt = line.split()
assert(line == line.strip())
assert(len(splt) == 2)
for x in splt:
    assert(not x.startswith('0'))
    assert(0 <= int(splt[0]) <= 10**9)
assert(sys.stdin.read() == '')

sys.exit(42)

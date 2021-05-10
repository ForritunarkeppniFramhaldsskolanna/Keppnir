import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**5
options = ["J", "N"]

for i in range(n):
    row = sys.stdin.readline().strip()
    assert len(row.split(" ")) == 3
    cpu, mem, hdd = row.split(" ")
    print(cpu in options)
    print(mem in options)
    print(hdd in options)
    assert cpu in options 
    assert mem in options 
    assert hdd in options

assert not sys.stdin.read()
sys.exit(42)

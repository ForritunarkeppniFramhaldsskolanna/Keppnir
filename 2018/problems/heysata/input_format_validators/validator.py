import sys
import string

def readline():
    line = sys.stdin.readline().rstrip('\n')
    assert(line == line.strip())
    return line

def notrash():
    assert(sys.stdin.read() == '')

line = readline()
n = int(line)
assert(str(n) == line)
k = readline()
assert(len(k) == 1 and k in string.ascii_letters)
heystack = readline()
assert(len(heystack) == n)
for i in heystack:
    assert(i in string.ascii_letters)
notrash()

sys.exit(42)

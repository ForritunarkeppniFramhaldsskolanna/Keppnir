import sys

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

with open(sys.argv[1], 'r') as f: inp = f.read()
with open(sys.argv[2], 'r') as f: outp = f.read()

a, b = map(int, outp.split('/'))
assert gcd(a,b) == 1

s = '%s.' % (a//b)
a %= b

while a != 0:
    a *= 10
    s += '%s' % (a // b)
    a %= b

assert s.rstrip('0') == inp.rstrip().rstrip('0')


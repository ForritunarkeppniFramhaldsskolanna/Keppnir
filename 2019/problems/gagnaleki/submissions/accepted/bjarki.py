import sys
import string

def xgcd(a, b):
    """return (g, x, y) such that a*x + b*y = g = gcd(a, b)"""
    x0, x1, y0, y1 = 0, 1, 1, 0
    while a != 0:
        q, b, a = b // a, a, b % a
        y0, y1 = y1, y0 - q * y1
        x0, x1 = x1, x0 - q * x1
    return b, x0, y0

def mulinv(a, b):
    """return x such that (x * a) % b == 1"""
    g, x, _ = xgcd(a, b)
    if g == 1:
        return x % b


magic = 0xb058592efd277ae75f27bd99d1628fbd
mod = 2**128
magic_inv = mulinv(magic, mod)

assert magic_inv * magic % mod == 1

def Hash(s, at):
    if at >= len(s):
        return 1

    return Hash(s, at+1) * 2**7 + s[at]

max_len = 20
constant = [ Hash([0]*l, 0) for l in range(max_len+1) ]
coeff = [ Hash([0]*(l-1) + [1], 0) - constant[l] for l in range(1,max_len+1) ]

def crack(target, l):
    target = (target * magic_inv - constant[l]) % mod

    res = ''
    for i in range(l-1,-1,-1):
        take = min(127, target // coeff[i])
        target -= coeff[i] * take
        res = chr(take) + res

    return res if target == 0 else None

valid_chars = set(string.digits + string.ascii_letters + string.punctuation + ' ')

n = int(sys.stdin.readline())

for i in range(n):
    line = sys.stdin.readline()
    line = line[:-1]
    target = eval('0x%s' % line)

    for l in range(0, max_len+1):
        ans = crack(target, l)
        if ans is not None:
            if not all( c in valid_chars for c in ans ):
                print(line, repr(ans))
            assert all( c in valid_chars for c in ans )
            print('%s:%s' % (line, ans))
            break


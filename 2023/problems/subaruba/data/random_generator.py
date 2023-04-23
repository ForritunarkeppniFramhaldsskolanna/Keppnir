#!/usr/bin/python3
import sys
import random
from string import ascii_letters

punctuation = ".,"
whitespace = "     "


OPTIONS = ascii_letters + punctuation + whitespace
VOWELS = ['A', 'Á', 'E', 'É', 'I', 'Í', 'O', 'Ó', 'U', 'Ú', 'Y', 'Ý', 'Æ', 'Ö']
KEY = "ub"

random.seed(int(sys.argv[-1]))

tp = sys.argv[1]
n = eval(sys.argv[2])
if n != 199997:
    OPTIONS += "\n"

def encrypt(s):
    res = []
    for c in s:
        if c.upper() in VOWELS:
            res.append(KEY.capitalize() if c.upper() == c else KEY)
            c = c.lower()
        res.append(c)
    return ''.join(res)

print(tp)
generated = ''.join([random.choice(OPTIONS) for _ in range(n)]).strip()
while '  ' in generated:
    generated = generated.replace('  ', ' ')
print(generated.count('\n')+1)
if tp == "A":
    print(encrypt(generated))
else:
    print(generated)

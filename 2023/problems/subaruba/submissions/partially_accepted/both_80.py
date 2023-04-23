#!/usr/bin/python3
import sys

VOWELS = ['A', 'Á', 'E', 'É', 'I', 'Í', 'O', 'Ó', 'U', 'Ú', 'Y', 'Ý', 'Æ', 'Ö']
KEY = "ub"

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

def encrypt(s):
    res = ""
    for c in s:
        if c.upper() in VOWELS:
            res = res + (KEY.capitalize() if c.upper() == c else KEY)
            c = c.lower()
        res = res + c
    return res

mode = sys.stdin.readline().strip()
n = int(sys.stdin.readline())
lines = sys.stdin.read()

if mode == "D":
    print(encrypt(lines))
else:
    print(decrypt(lines))

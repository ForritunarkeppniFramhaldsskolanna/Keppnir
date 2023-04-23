#!/usr/bin/python3
import sys

VOWELS = ['A', 'Á', 'E', 'É', 'I', 'Í', 'O', 'Ó', 'U', 'Ú', 'Y', 'Ý', 'Æ', 'Ö']
KEY = "ub"

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

print(encrypt(lines))

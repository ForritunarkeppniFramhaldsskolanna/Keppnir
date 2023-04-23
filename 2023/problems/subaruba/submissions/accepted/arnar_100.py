#!/usr/bin/python3
import sys

    

VOWELS = ['A', 'Á', 'E', 'É', 'I', 'Í', 'O', 'Ó', 'U', 'Ú', 'Y', 'Ý', 'Æ', 'Ö']
KEY = "ub"

def encrypt(s):
    res = []
    for c in s:
        if c.upper() in VOWELS:
            res.append(KEY.capitalize() if c.upper() == c else KEY)
            c = c.lower()
        res.append(c)
    return ''.join(res)

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

mode = sys.stdin.readline()
n = int(sys.stdin.readline())
lines = sys.stdin.read()

if mode == "D\n":
    res = encrypt(lines)
    if len(sys.argv) > 1 and sys.argv[1] == "statement":
        KEYWORDS = [
            "\\emph",
            "\\section",
            "\\cdot",
            "{tabular}",
            "\\problemname",
            "\\texttt",
            "\\illustration",
            "\\href",
            "\\begin",
            "\\end",
            "\\hline"
        ]
        for keyword in KEYWORDS:
            res = res.replace(encrypt(keyword), keyword)
    print(res)
else:
    print(decrypt(lines))

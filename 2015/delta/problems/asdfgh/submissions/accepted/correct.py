import sys
import string

keyborat = [
    'pyfgcrl',
    'aoeuidhtns',
    'qjkxbmwvz',
]

streng = sys.stdin.readline().rstrip()

if any([set(streng) <= set(line) for line in keyborat]):
    print("Jebb")
else:
    print("Neibb")

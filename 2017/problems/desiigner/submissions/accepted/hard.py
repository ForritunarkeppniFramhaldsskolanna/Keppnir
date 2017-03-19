import sys
import re

s = sys.stdin.readline().strip()
if re.match("^br{2,}[a, e, i, o, u, y]$", s):
    print("Jebb")
    exit()
print("Neibb")

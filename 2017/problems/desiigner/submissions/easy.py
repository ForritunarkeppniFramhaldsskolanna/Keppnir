import sys
import re

s = sys.stdin.readline().strip()
if re.match("^br{2,}a$", s):
    print("Jebb")
    exit()
print("Neibb")

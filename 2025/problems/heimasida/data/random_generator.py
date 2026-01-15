#!/usr/bin/python3
import sys
import random
import string

random.seed(int(sys.argv[-1]))

level = int(sys.argv[1])

allowed = list(string.printable)

if level == 0:
    allowed = list(string.ascii_letters)
elif level == 2:
    for c in "ÁáÐðÉéÍíÓóÚúÝýÞþÆæÖö":
        allowed.append(c)

for c in string.whitespace:
    if c == " ":
        continue
    if allowed.count(c):
        del allowed[allowed.index(c)]

l = random.randint(80, 100)

res = []
for _ in range(l):
    res.append(random.choice(allowed))

print("".join(res))

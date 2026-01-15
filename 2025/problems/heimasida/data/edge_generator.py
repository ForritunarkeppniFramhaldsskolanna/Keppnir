#!/usr/bin/python3
import sys
import random
import string

random.seed(int(sys.argv[-1]))

case = int(sys.argv[1])

allowed = list(string.printable)

for c in string.whitespace:
    if c == " ":
        continue
    if allowed.count(c):
        del allowed[allowed.index(c)]

if case == 0:
    allowed = list(string.ascii_letters)
    random.shuffle(allowed)
    print("".join(allowed))
elif case == 1:
    random.shuffle(allowed)
    print("".join(allowed))
elif case == 2:
    allowed = list("ÁáÐðÉéÍíÓóÚúÝýÞþÆæÖö")
    random.shuffle(allowed)
    print("".join(allowed))
elif case == 3:
    print("")
elif case == 4:
    print("         ")
elif case == 5:
    print("*~~~*!!!&&??<<===>>::;:;")

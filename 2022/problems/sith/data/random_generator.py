#!/bin/env python3
import sys
import random

MIN_VAL = 1
MAX_VAL = 100

random.seed(int(sys.argv[-1]))

result = sys.argv[1].upper()

jedi_names = []
sith_names = []
unknown_names = []

with open("list_of_jedi.txt", "r") as f:
    jedi_names = f.readlines()
with open("list_of_sith.txt", "r") as f:
    sith_names = f.readlines()
with open("list_of_unknown.txt", "r") as f:
    unknown_names = f.readlines()

name = ""
names = []
a = random.randint(MIN_VAL, MAX_VAL)
b = a

ab = 0
if result == "JEDI":
    while b == a:
        b = random.randint(MIN_VAL, MAX_VAL)
    if a > b:
        a,b = b,a
    ab = a-b
    names = jedi_names
elif result == "SITH":
    while b == a:
        b = random.randint(MIN_VAL, MAX_VAL)
    if a > b:
        a,b = b,a
    ab = abs(a-b)
    names = sith_names
else:
    b = random.randint(MIN_VAL, MAX_VAL)
    if a < b:
        a,b = b,a
    ab = a-b
    names = unknown_names

name = random.choice(names).strip()
sys.stdout.write("{}\n".format(name))
sys.stdout.write("{}\n".format(a))
sys.stdout.write("{}\n".format(b))
sys.stdout.write("{}\n".format(ab))

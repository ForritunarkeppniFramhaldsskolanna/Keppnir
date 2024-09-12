#!/usr/bin/python3
import sys
from random import randint, seed, choices
import string

seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
upper = bool(int(sys.argv[3]))
lower = bool(int(sys.argv[4]))
only_valid = bool(int(sys.argv[5]))

n = randint(min_n, max_n)
letter_pool = ""

if upper:
    letter_pool += string.ascii_uppercase

if lower:
    letter_pool += string.ascii_lowercase

if not only_valid:
    letter_pool += string.punctuation

s = ''.join(choices(letter_pool, k=n))

sys.stdout.write(f"{s}\n")

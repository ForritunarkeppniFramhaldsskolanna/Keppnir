#!/usr/bin/python3
import sys
import random
from string import ascii_letters

random.seed(int(sys.argv[-1]))

ascii_letters += '0123456789"()'

min_n: int = int(sys.argv[1])
max_n: int = int(sys.argv[2])

number1: int = random.randint(min_n, max_n)
number2: int = random.randint(min_n, max_n)

s1: str = "".join(random.choices(ascii_letters, k=number1))
s2: str = "".join(random.choices(ascii_letters, k=number2))

sys.stdout.write(f"{s1}\n")
sys.stdout.write(f"{s2}\n")

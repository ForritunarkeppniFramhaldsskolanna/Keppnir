#!/usr/bin/python3
import sys
import random

from string import ascii_letters

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
gen_type = sys.argv[3]
assert gen_type in ["always_start_upper", "any_start"]

n = random.randint(min_n, max_n)

def make_word(gen_type):
    size = random.randint(1, 10)
    chars = [random.choice(ascii_letters) for _ in range(size)]
    if gen_type == "always_start_upper":
        chars[0] = chars[0].upper()
    return ''.join(chars)

words = [make_word(gen_type) for _ in range(n)]

sys.stdout.write("{}\n".format(n))
print(' '.join(words))

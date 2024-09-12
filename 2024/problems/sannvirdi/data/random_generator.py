#!/usr/bin/python3
import random
import string
import sys

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
min_q = eval(sys.argv[3])
max_q = eval(sys.argv[4])

MIN_GUESS = 0
MAX_GUESS = 10**9

names = set()
guesses = set()

n = random.randint(min_n, max_n)
q = random.randint(min_q, max_q)

def generate_name():
    return "".join([random.choice(string.ascii_lowercase) for _ in range(random.randint(1, 6))])

def generate_guess():
    return random.randint(MIN_GUESS, MAX_GUESS)

def generate_unique(func, already_existing):
    while (val := func()) in already_existing:
        pass
    return val

print(f"{n}")
for _ in range(n):
    name = generate_unique(generate_name, names)
    guess = generate_unique(generate_guess, guesses)

    names.add(name)
    guesses.add(guess)
    
    print(f"{name} {guess}")

print(f"{q}")
for _ in range(q):
    idea = generate_guess()
    print(f"{idea}")

#!/usr/bin/python3
import sys
import random
import string

random.seed(int(sys.argv[-1]))

test_type = sys.argv[1]
min_n = int(sys.argv[2])
max_n = int(sys.argv[3])
min_m = int(sys.argv[4])
max_m = int(sys.argv[5])

n = random.randint(min_n, max_n)
m = random.randint(min_m, max_m)

def random_name():
    size = random.randint(2, 10)
    return ''.join(random.choice(string.ascii_lowercase) for i in range(size)).capitalize()

def random_full_name(test_type):
    if test_type == "one":
        return random_name(), ""
    elif test_type == "two":
        return random_name(), random_name()
    elif test_type == "any":
        return random_full_name(random.choice(["one", "two"]))
    else:
        assert False

def random_visit(home):
    if random.choice(['home', 'probably not']) == 'home':
        return random.choice(home).split()[0]
    return random_name()

home = dict()
while len(home) < n:
    first_name, second_name = random_full_name(test_type)
    home[first_name] = second_name
home = ["{} {}".format(first_name, second_name).strip() for first_name, second_name in home.items()]

visits = []
for j in range(m):
    visits.append(random_visit(home))

sys.stdout.write("{}\n".format(n))
for full_name in home:
    sys.stdout.write("{}\n".format(full_name))

sys.stdout.write("{}\n".format(m))
for visit in visits:
    sys.stdout.write("{}\n".format(visit))

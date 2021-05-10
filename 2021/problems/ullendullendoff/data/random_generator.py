import sys
import random
import string

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

n = random.randint(min_n, max_n)

def random_name():
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(random.randint(1, 10))).capitalize()

sys.stdout.write("{}\n".format(n))

names = set()
while len(names) < n:
    names.add(random_name())

sys.stdout.write(' '.join(list(names)))
sys.stdout.write('\n')

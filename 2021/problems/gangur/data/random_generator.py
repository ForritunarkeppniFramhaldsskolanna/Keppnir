import sys
import random

random.seed(int(sys.argv[-1]))

group = sys.argv[1]
min_n = int(sys.argv[2])
max_n = int(sys.argv[3])

n = random.randint(min_n, max_n)
density = random.uniform(0, 1)

if group == "single":
    sys.stdout.write(">")
    for i in range(n-1):
        if random.uniform(0, 1) > density:
            sys.stdout.write("<")
        else:
            sys.stdout.write("-")

elif group == "split":
    splitpoint = random.randint(0, n)
    for i in range(n):
        if random.uniform(0, 1) > density:
            sys.stdout.write(">" if i < splitpoint else "<")
        else:
            sys.stdout.write("-")

elif group == "random":
    left_right = random.uniform(0, 1)
    for i in range(n):
        if random.uniform(0, 1) > density:
            sys.stdout.write(">" if random.uniform(0,1) < left_right else "<")
        else:
            sys.stdout.write("-")
else:
    assert False

sys.stdout.write("\n")

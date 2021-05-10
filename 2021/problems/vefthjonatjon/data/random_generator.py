import sys
import random
import string

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

binary_options = ["J", "N"]

n = random.randint(min_n, max_n)
sys.stdout.write(str(n) + "\n")
for i in range(n):
    bits = [random.choice(binary_options) for _ in range(3)]
    bitstring = " ".join(bits)
    sys.stdout.write(bitstring + "\n")

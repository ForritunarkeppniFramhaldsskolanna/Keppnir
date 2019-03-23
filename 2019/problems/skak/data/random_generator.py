import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: Given values

blah = random.randint(0,2)
x = random.randint(1,10**5)
y = random.randint(1,10**5)
while True:
    u = random.randint(1,10**5) if blah != 0 else x
    v = random.randint(1,10**5) if blah != 1 else y
    if u == x and v == y:
        continue
    break
print(str(x) + " " + str(y))
print(str(u) + " " + str(v))


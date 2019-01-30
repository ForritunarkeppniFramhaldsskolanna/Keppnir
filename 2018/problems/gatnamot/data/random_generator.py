import sys
from random import randint

# Type of testcase:
#   1: small
#   2: large
tc = int(sys.argv[1])

r = 0
if tc == 1:
    r = randint(1,1999)
elif tc == 2:
    r = randint(2001,999999)
elif tc == 3:
    r = 2000
elif tc == 4:
    r = 1000000
print(r)

import sys
from random import randint
import string

minN, maxN, match, endMatch = [int(i) for i in sys.argv[1:5]]

n = randint(minN, maxN)
k = None
heystack = None
letters = string.ascii_letters
if match:
    heystack = "".join([string.ascii_letters[randint(0, len(string.ascii_letters)-1)] for i in range(n)])
    if endMatch:
        k = heystack[n-1]
    else:
        k = heystack[randint(0, n-1)]
else:
    k = string.ascii_letters[randint(0, len(string.ascii_letters)-1)]
    letters = string.ascii_letters
    letters = "".join([x for x in letters if x != k])
    heystack = "".join([letters[randint(0, len(letters)-1)] for i in range(n)])

print(n)
print(k)
print(heystack)

import sys
from random import randint
import random
import string
# Type of testcase:
#   1: small
#   2: large
tc = int(sys.argv[1])

n = -1
if tc == 1:
    n = 1
elif tc == 2:
    n = randint(1, 10**4)
print(n)
for _ in range(n):
    capitlize_first = random.randint(0, 1) 
    #non = " ".join(["".join([random.choice(string.ascii_lowercase) for _ in range(randint(1, 20))]) for i in range(10)])
    #nonmeme_string = " ".join(["".join([random.choice(string.ascii_lowercase) for _ in range(randint(1, 20))]) for i in range(randint(1, 20))])
    nonmeme_string = "".join([random.choice(string.ascii_lowercase) for _ in range(randint(1, 200))])
    meme_string = "".join([c.upper() if i % 2 == capitlize_first else c for i, c in enumerate(nonmeme_string)])

    meme_string_spaced = ""
    
    j = 0
    while j < len(meme_string):
        meme_string = meme_string[:j] + " " + meme_string[j:]
        rand = randint(1, 20)
        j += rand + 1
    print(meme_string.strip() + ".")
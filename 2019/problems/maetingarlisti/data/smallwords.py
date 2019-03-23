import sys
from random import randint
import random
import string

# Type of testcase:

allwords = []

def gen(word):
    if len(word) > 20:
        return
    global allwords
    if len(allwords) == 10**5:
        return
    if len(word) > 0:
        allwords.append(word)
    for x in range(97,123):
        gen(word+chr(x))


gen("")
print(str(10**5) + " " + str(1) + " " + str(10**5))
print(' '.join(allwords))
for x in allwords:
    print(x)

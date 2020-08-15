import sys
import random
import string

random.seed(int(sys.argv[-1]))

chars = list(string.ascii_letters)
vowels = list("aeoiuAEOIU")

n = eval(sys.argv[1])
perc = eval(sys.argv[2])

outstr = []

for i in range(n):
  if random.random() >= perc:
    outstr.append(random.choice(chars))
  else:
    outstr.append(random.choice(vowels))

print("".join(outstr))

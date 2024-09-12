#!/usr/bin/python3
import sys, random

random.seed(int(sys.argv[-1]))

print(sys.argv[1])

l = random.choice([999, random.randint(47, 999)])

opts = "~1234567890-=qwertyuiop[]asdfghjkl;\'zxcvbnm,./ "

outp = []
for c in opts:
    outp.append(c)
while len(outp) < l:
    outp.append(random.choice(opts))
random.shuffle(outp)
print("".join(outp))

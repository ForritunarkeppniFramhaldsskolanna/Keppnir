#!/usr/bin/env python3
import sys
import os
import binascii

input_file = sys.argv[1]
answer_file = sys.argv[2]
feedback_dir = sys.argv[3]

MOD = 2**128
MAGIC = 0xb058592efd277ae75f27bd99d1628fbd
def calcHash(s):
    res = MAGIC
    for at in range(len(s)-1, -1, -1):
        res = (res * (2**7) + MAGIC * s[at]) % MOD

    t = ''
    for i in range(32):
        t += hex(res % 16)[-1]
        res = res//16

    return t[::-1].encode()

hashes = set()
cracked = set()
with open(input_file, 'rb') as f:
    for line in f:
        line = line[:-1]
        hashes.add(line)

def finish(score):
    with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
        f.write('%d\n' % score)
    if score == 0:
        sys.exit(43)
    sys.exit(42)

inp = sys.stdin.buffer.read()
for line in inp.split(b'\n'):
    if line.endswith(b'\r'):
        line = line[:-1]

    if b':' not in line:
        continue

    k, v = line.split(b':', 1)
    if k not in hashes or k in cracked:
        continue

    if len(v) <= 1000 and calcHash(v) == k:
        cracked.add(k)

finish((100 * len(cracked) + len(hashes) - 1) // len(hashes))

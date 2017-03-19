import sys
import random

sys.stdout.write("""#!/usr/bin/env bash
PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

setup_dirs
use_solution sol.cpp

compile H.py

samplegroup
sample 1
sample 2

""")

# 10 tiny numbers (< 10)
for n in range(10):
    sys.stdout.write("""
group tiny-%d 1
tc tiny-%d H %d
""" % (n,n, n))

# 10 small numbers (< 1000)
for n in range(10):
    sys.stdout.write("""
group small-%d 1
tc small-%d H %d
""" % (n,n, random.randint(1,1000)))

# 7 Perfect numbers
for i,n in enumerate([
6,
28,
496,
8128,
33550336,
8589869056,
137438691328,
    ]):
    sys.stdout.write("""
group perfect-%d 1
tc perfect-%d H %d
""" % (i,i, n))

# 10 Factorial numbers
for i,n in enumerate([
362880,
5040,
121645100408832000,
120,
6227020800,
3628800,
87178291200,
355687428096000,
1307674368000,
6402373705728000,
    ]):
    sys.stdout.write("""
group factorial-%d 1
tc factorial-%d H %d
""" % (i,i, n))

# 10 2^n
for i,n in enumerate([
4294967296,
137438953472,
576460752303423488,
16777216,
144115188075855872,
72057594037927936,
288230376151711744,
4503599627370496,
8388608,
64,
    ]):
    sys.stdout.write("""
group p2-%d 1
tc p2-%d H %d
""" % (i,i, n))

# 10 Fibonacci numbers
for i,n in enumerate([
160500643816367088,
259695496911122585,
806515533049393,
1836311903,
139583862445,
679891637638612258,
420196140727489673,
8944394323791464,
610,
61305790721611591,
    ]):
    sys.stdout.write("""
group fibonacci-%d 1
tc fibonacci-%d H %d
""" % (i,i, n))

# 10 Catalan numbers
for i,n in enumerate([
55534064877048198,
212336130412243110,
343059613650,
14544636039226909,
2674440,
1767263190,
42,
263747951750360,
91482563640,
129644790,
    ]):
    sys.stdout.write("""
group catalan-%d 1
tc catalan-%d H %d
""" % (i,i, n))

# 10 Motzkin numbers
for i,n in enumerate([
66368199913921497,
41835,
13933569346707,
2750016719520991,
73007772802,
953467954114363,
400763223,
556704809728838604,
22944749046030949,
192137918101841817,
    ]):
    sys.stdout.write("""
group motzkin-%d 1
tc motzkin-%d H %d
""" % (i,i, n))

# 10 Triangular numbers
for i in range(10):
    n = random.randint(0,1414213561)
    sys.stdout.write("""
group triangluar-%d 1
tc triangluar-%d H %d
""" % (i,i, n*(n+1)//2))

# 13 large numbers
for i in range(13):
    sys.stdout.write("""
group large-%d 1
tc large-%d H %d
""" % (i,i, random.randint(0, 10**18)))


sys.stdout.write("""
generate_grader
cleanup_programs
""")


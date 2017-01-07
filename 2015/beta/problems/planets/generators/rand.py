import sys
import random
import string
from math import sqrt

MN = -10000.0
MX = 10000.0

if len(sys.argv) < 2:
    N = random.randint(1,10000)
else:
    N = int(sys.argv[1])

sys.stdout.write("{}\n".format(N))
earth = ( random.uniform(MN, MX), random.uniform(MN, MX), random.uniform(MN, MX) )
sys.stdout.write("{0[0]:.5f} {0[1]:.5f} {0[2]:.5f}\n".format(earth))

dists = set()

def dist(pl1, pl2):
    return sqrt((pl1[0] - pl2[0])**2 + (pl1[1] - pl2[1])**2 + (pl1[2] - pl2[2])**2)

def check(pl):
    for d in dists:
        if abs(dist(pl, earth) - d) < 1e-6:
            return False
    return True

for i in range(N):
    planet = (random.uniform(MN, MX), random.uniform(MN, MX), random.uniform(MN, MX))
    while not check(planet):
        planet = (random.uniform(MN, MX), random.uniform(MN, MX), random.uniform(MN, MX))
    sys.stdout.write("{0[0]:.5f} {0[1]:.5f} {0[2]:.5f}\n".format(planet))


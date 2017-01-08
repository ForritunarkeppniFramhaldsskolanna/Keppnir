#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys

N = int(sys.argv[1])
Q = int(sys.argv[2])
method = sys.argv[3]
only_valid = int(sys.argv[4])
random.seed(int(sys.argv[5]))

# Generates a few pretty wide trees, generally, with eventual cycles of
# rather small size. Good for testing correctness.
def gen_random(N):
    return [random.randint(1, N) for _ in range(N)]

# Generate a single long path, as a possible worst case.
def gen_path(N):
    return [max(1, x) for x in range(N)]

# As above but in opposite direction.
def gen_path_reverse(N):
    return [min(N, x+2) for x in range(N)]

# Generate a single cycle, with a small number of in-edges, as another worst case.
def gen_cycle(N):
    in_ed = N // 10
    cycle_ed = N - in_ed
    perm = list(range(cycle_ed))
    random.shuffle(perm)
    cycle = perm[:]
    for i in range(cycle_ed):
        cycle[perm[i]] = perm[(i+1) % cycle_ed] + 1
    return cycle + [random.randint(1, cycle_ed) for _ in range(in_ed)]

lines = [N]
if method == 'random':
    lines += gen_random(N)
elif method == 'path' or method == 'path2':
    lines += gen_path(N)
elif method == 'reverse':
    lines += gen_path_reverse(N)
elif method == 'cycle':
    lines += gen_cycle(N)
else:
    assert False
lines = map(str, lines)

sample_q = only_valid*Q if only_valid else Q
sample_lines = [str(sample_q)]
inds = list(range(N))
for q in range(sample_q):
    [a, b] = random.sample(inds, 2)
    line = '{} {}'.format(a+1, b+1)
    sample_lines.append(line)

if only_valid:
    sample_input = '\n'.join(lines + sample_lines)
    p = subprocess.Popen(['./sol'], stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    sample_output = p.communicate(input=sample_input)[0]
    query_lines = []
    index = 1
    for output in sample_output.split('\n'):
        if output and output != '-1':
            query_lines.append(sample_lines[index])
            if len(query_lines) >= Q:
                break
        index += 1
    query_lines.insert(0, str(len(query_lines)))
else:
    query_lines = sample_lines

if method == 'path2':
    # Use worst-case queries instead, for a constant factor slowdown.
    sq = int(math.sqrt(Q))
    assert 2*sq <= N
    query_lines = [str(sq*sq)]
    for a in range(sq):
        for b in range(sq):
            query_lines.append('{} {}'.format(N-b, 1+a))

print('\n'.join(lines + query_lines))
sys.stderr.write("wrote N={}, Q={}\n".format(N, query_lines[0]))

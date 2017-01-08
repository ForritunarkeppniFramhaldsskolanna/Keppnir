#!/usr/bin/env python

import sys
import subprocess

lines = []
N = int(sys.stdin.readline().strip().split()[0])
lines.append('digraph {')
line = sys.stdin.readline().strip().split()
for a in range(1, N+1):
    b = line[a-1]
    lines.append('  {} -> {};'.format(a, b))
lines.append('}')

p = subprocess.Popen("dot -T png | display", shell=True, stdin=subprocess.PIPE)
p.communicate(input='\n'.join(lines))

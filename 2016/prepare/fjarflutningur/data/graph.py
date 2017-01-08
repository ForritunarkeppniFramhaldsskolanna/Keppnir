#!/usr/bin/env python

import subprocess

lines = []
N = int(raw_input())
lines.append('digraph {')
for a in range(1, N+1):
    b = int(raw_input())
    lines.append('  {} -> {};'.format(a, b))
lines.append('}')

p = subprocess.Popen("dot -T png | display", shell=True, stdin=subprocess.PIPE)
p.communicate(input='\n'.join(lines))

#!/usr/bin/env python2
import sys
input_file = sys.argv[1]
answer_file = sys.argv[2]
feedback_dir = sys.argv[3]

output = sys.stdin.read()

with open(answer_file, 'r') as f:
    answer = f.read()

def fix(s):
    lines = s.replace('\r','\n').split('\n')
    ans = []
    for l in lines:
        cur = l.strip().replace(' ', '')
        if cur:
            ans.append(cur)
    return sorted(ans)

if fix(output) == fix(answer):
    sys.exit(42)
else:
    sys.exit(43)


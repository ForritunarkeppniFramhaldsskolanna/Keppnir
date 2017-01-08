#!/usr/bin/env python2
import sys
import os
input_file = sys.argv[1]
answer_file = sys.argv[2]
feedback_dir = sys.argv[3]

output = sys.stdin.read()

with open(answer_file, 'r') as f:
    answer = f.read()

def fix(s):
    ans = []
    for l in s.replace('\r', '\n').split('\n'):
        l = l.replace(' ', '')
        if l:
            ans.append(l)
    return ans

ans = sorted(fix(answer))
out = sorted(fix(output))

if ans == out:
    with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
        f.write('1.0\n')
    sys.exit(42)
else:
    with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
        f.write('0.0\n')
    sys.exit(43)


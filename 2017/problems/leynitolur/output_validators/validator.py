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

ans = fix(answer)
out = fix(output)

cnt = 0
for (a,b) in zip(ans,out):
    if a == b:
        cnt += 1

with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
    f.write('%0.10f\n' % (float(cnt) / len(ans)))
sys.exit(42)

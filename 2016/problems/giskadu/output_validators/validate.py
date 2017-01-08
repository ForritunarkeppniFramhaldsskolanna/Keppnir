#!/usr/bin/env python2
import sys
import os
input_file = sys.argv[1]
answer_file = sys.argv[2]
feedback_dir = sys.argv[3]

output = sys.stdin.read()

answer = 273

try:
    output = int(output)
except:
    with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
        f.write('0\n')
    sys.exit(43)

dist = abs(answer - output)
score = 100 - min(dist, 100)
with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
    f.write('%0.10f\n' % (float(score) / 100.0))
sys.exit(42)


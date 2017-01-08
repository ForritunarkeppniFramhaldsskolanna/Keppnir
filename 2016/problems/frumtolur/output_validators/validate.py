#!/usr/bin/env python2
import sys
import os
input_file = sys.argv[1]
answer_file = sys.argv[2]
feedback_dir = sys.argv[3]

output = sys.stdin.read()

answer = '''
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
101
103
107
109
113
127
131
137
139
149
151
157
163
167
173
179
181
191
193
197
199
211
223
227
229
233
239
241
251
257
263
269
271
277
281
283
293
307
311
313
317
331
337
347
349
353
359
367
373
379
383
389
397
401
409
419
421
431
433
439
443
449
457
461
463
467
479
487
491
499
503
509
521
523
541
'''

def fix(s):
    ans = []
    for l in s.replace('\r', '\n').split('\n'):
        l = l.replace(' ', '')
        if l:
            ans.append(l)
    return ans

ans = set(fix(answer))
out = set(fix(output))

if out <= ans:
    with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
        f.write('%0.10f\n' % (float(len(out)) / len(ans)))
    sys.exit(42)
else:
    with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
        f.write('0\n')
    sys.exit(43)


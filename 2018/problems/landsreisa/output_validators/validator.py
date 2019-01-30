import sys
import os
from math import sqrt
input_file = sys.argv[1]
answer_file = sys.argv[2]
feedback_dir = sys.argv[3]

output = sys.stdin.read()
n,points = None,None
fail = False
def dist(p1, p2):
    xd = p1[0]-p2[0]
    yd = p1[1]-p2[1]
    return sqrt(xd*xd+yd*yd)
try:
    with open(input_file) as f:
        n = int(f.readline())
        points = [tuple(map(float, f.readline().split())) for i in range(n)]
except:
    fail = True
try:
    output = list(map(int, output.split()))
except:
    fail = True
if fail or n != len(points) or n != len(output) or output[0] != 0 or len(set(output)) != n or not all(0 <= x <= n-1 for x in output):
    with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
        f.write('0')
    sys.exit(43)

#tour = None
#with open(answer_file) as f:
#    tour = list(map(int, f.read().split()))
#opt = 0.0
#for i in range(n):
#    opt += dist(points[tour[i]], points[tour[(i+1)%n]])

tour = output
ans = 0.0
for i in range(n):
    ans += dist(points[tour[i]], points[tour[(i+1)%n]])

p100 = 60.0
p0 = 90.0

ans = min(p0, max(ans, p100))

with open(os.path.join(feedback_dir, 'score.txt'), 'w') as f:
    f.write('%d\n' % int(100 * (p0-ans)/(p0-p100)))
sys.exit(42)

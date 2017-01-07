import random
import math

def rand(a, b):
    return b - random.random() * (b - a)

for t in range(10):
    a = rand(0, 10000)
    b = rand(0, a)

    with open('%02d.in' % t, 'w') as f:
        f.write('%0.10lf\n' % a)
        f.write('%0.10lf\n' % b)

    with open('%02d.ans' % t, 'w') as f:
        f.write('%0.10lf\n' % math.sqrt(a*a - b*b))


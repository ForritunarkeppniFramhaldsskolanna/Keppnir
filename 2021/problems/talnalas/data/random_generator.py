import sys
import random
import string

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
max_m = eval(sys.argv[2])
tp = sys.argv[3]

def random_rotate(s):
    i = random.randint(0, n-1)
    d = s[i]
    if random.randint(0,1) == 0:
        if d == '0':
            d = '9'
        else:
            d = str(int(d) - 1)
    else:
        if d == '9':
            d = '0'
        else:
            d = str(int(d) + 1)
    s = s[:i] + d + s[i+1:]
    return s

vertices = set()
if tp == 'random_walk':
    start = ''.join( random.choice(string.digits) for i in range(n) )
    vertices.add(start)
    end = start
    while len(vertices) != max_m+2:
        end = random_rotate(end)
        vertices.add(end)
elif tp == 'random_walk_change_one':
    start = ''.join( random.choice(string.digits) for i in range(n) )
    vertices.add(start)
    end = start
    while len(vertices) != max_m+2:
        end = random_rotate(end)
        vertices.add(end)
    while True:
        r = random.choice(list(vertices))
        if r not in {start,end}:
            break
    vertices.remove(r)
    while len(vertices) != max_m+2:
        r = random.choice(list(vertices))
        vertices.add(random_rotate(r))
elif tp == 'random_walk_multi':
    k = random.randint(2, min(10, max_m//2))
    each_m = max_m//k
    start = ''.join( random.choice(string.digits) for i in range(n) )
    vertices.add(start)
    for i in range(k):
        orig_len = len(vertices)
        end = start
        while len(vertices)-orig_len != each_m:
            end = random_rotate(end)
            vertices.add(end)
elif tp == 'random_walk_noise':
    start = ''.join( random.choice(string.digits) for i in range(n) )
    vertices.add(start)
    end = start
    while len(vertices) != max_m//2+2:
        end = random_rotate(end)
        vertices.add(end)
    while len(vertices) != max_m+2:
        vertices.add(''.join( random.choice(string.digits) for i in range(n) ))

assert start in vertices
assert end in vertices
print('%d %d' % (n, len(vertices)-2))
print('%s' % start)
print('%s' % end)
vertices = list(vertices)
random.shuffle(vertices)
for v in vertices:
    if v not in {start,end}:
        print('%s' % v)


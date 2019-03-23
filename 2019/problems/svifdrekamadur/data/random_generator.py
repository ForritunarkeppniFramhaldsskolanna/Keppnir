import sys
import random

if sys.argv[1] == 'x':
    print('5')
    print('5 5 6 5 5')
    sys.exit(0)

if sys.argv[1] == 'y':
    print('3')
    print('2 1 2')
    sys.exit(0)

if sys.argv[1] == 'incr':
    print('3')
    print('1 2 3')
    sys.exit(0)

if sys.argv[1] == 'decr':
    print('3')
    print('3 2 1')
    sys.exit(0)

# Type of testcase:
#   1: min_n
#   2: max_n
#   3: min_a
#   4: max_a
#   5: seed
min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
min_a = int(sys.argv[3])
max_a = int(sys.argv[4])
if len(sys.argv) > 5:
    random.seed(int(sys.argv[5]))

arr = []
n = 0
k = 0

def get(n,mn,mx):
    sol = []
    for x in range(n):
        sol.append(random.randint(mn,mx))
    return sol

n = random.randint(min_n, max_n)
arr = get(n, min_a, max_a)

print(str(n))
ok = []
for x in range(n):
    ok.append(str(arr[x]))
print(' '.join(ok))


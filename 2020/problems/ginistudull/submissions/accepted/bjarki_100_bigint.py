import sys

n = int(sys.stdin.readline())
arr = list(sorted([ int(sys.stdin.readline()) for _ in range(n) ]))
sm = sum(arr)

pref = 0
sm1 = 0
for i in range(n):
    left = pref
    right = sm - arr[i] - pref

    sm1 += i * arr[i] - left
    sm1 += right - (n-i-1) * arr[i]

    pref += arr[i]

sm2 = 2 * n * sm

sys.stdout.write('%d.' % (sm1 // sm2))

for i in range(30):
    sm1 %= sm2
    sm1 *= 10
    sys.stdout.write('%d' % (sm1 // sm2))

sys.stdout.write('\n')


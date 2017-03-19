import sys
k = int(sys.stdin.readline())
k -= 1
l = 1

while True:
    if k < 8**l:
        res = []
        for _ in range(l):
            res.append(k % 8)
            k = k // 8
        for x in res[::-1]:
            if x == 0: sys.stdout.write('1')
            if x == 1: sys.stdout.write('2')
            if x == 2: sys.stdout.write('3')
            if x == 3: sys.stdout.write('4')
            if x == 4: sys.stdout.write('5')
            if x == 5: sys.stdout.write('6')
            if x == 6: sys.stdout.write('7')
            if x == 7: sys.stdout.write('9')
        sys.stdout.write('\n')
        break
    else:
        k -= 8**l
    l += 1


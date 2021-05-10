#!python3
n, k = [int(x) for x in input().strip().split()]

if k == 1 or k == 3:
    ans = n * (n + 1)
    ans %= 10 ** 9 + 7
    ans *= 500000004
    ans %= 10 ** 9 + 7
    if k == 3:
        ans *= ans
        ans %= 10 ** 9 + 7
    print(ans)
elif k == 2:
    ans = n * (n + 1)
    ans %= 10 ** 9 + 7
    ans *= 2 * n + 1
    ans %= 10 ** 9 + 7
    ans *= 166666668
    ans %= 10 ** 9 + 7
    print(ans)
else:
    sm = 0
    md = 10 ** 9 + 7

    for i in range(1, n + 1):
        sm += pow(i, k, md)
        sm %= md

    print(sm)


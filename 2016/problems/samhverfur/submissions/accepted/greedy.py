#!/usr/bin/python3

def dec(arr, ind):
    while True:
        arr[ind] = (arr[ind] - 1) % 10
        if arr[ind] == 9:
            ind -= 1
        else:
            break


def do_stuff(n):
    n = list(map(int,str(n)))
    le = len(n)
    middle = le // 2
    for i in range(middle):
        corr = le - i - 1
        beg, end = n[i], n[corr]

        # All zeros from center to corr
        if beg > end and not any(n[middle:corr]):
            # borrow from element to the left of center
            dec(n, middle - 1)

            for j,k in enumerate(range(corr, middle - 1, -1)):
                 n[k] = n[i+j]

            if le % 2 == 1:
                n[le // 2] = 9
            break

        n[corr] = beg
        if end < beg:
            dec(n, corr-1)


    return ''.join(map(str,n))

for i in range(1,101):
    res = do_stuff(2 ** i)
    print(i, res)
    assert res == res[::-1]
    assert int(res) <= 2 ** i

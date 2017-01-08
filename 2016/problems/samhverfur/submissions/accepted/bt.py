from __future__ import print_function

for k in range(1,101):
    num = str(2**k)

    res = [ -1 for _ in range(len(num)) ]
    def bt(at, same):
        if at >= len(res) or res[at] != -1:
            here = int(''.join(map(str, res)))
            if here <= int(num):
                print(k, here)
                return True
            return False
        d = 9
        if same:
            d = int(num[at])
        while d >= 0:
            if d == 0:
                assert at > 0
            res[at] = d
            res[len(res)-1-at] = d
            if bt(at+1, same and d == int(num[at])):
                return True
            res[at] = -1
            res[len(res)-1-at] = -1
            d -= 1
        return False

    bt(0,True)


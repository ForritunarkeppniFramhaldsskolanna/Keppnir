
def heiltala(c):
    if '0' <= c <= '9':
        return int(c)
    return ord(c) - ord('a') + 10

def stafur(c):
    if 0 <= c <= 9:
        return str(c)
    return chr(ord('a') + c - 10)

def leggjaSaman(a, b):
    carry = 0
    s = ''
    for at in range(31, -1, -1):
        carry += heiltala(a[at]) + heiltala(b[at])
        s = stafur(carry % 16) + s
        carry = carry // 16
    return s

def brengla(s, at, u):
    magic = 'b058592efd277ae75f27bd99d1628fbd'
    if at >= len(s):
        return magic

    res = leggjaSaman(brengla(s, at+1, True), brengla(s, at+1, False))
    for i in range(6):
        res = leggjaSaman(res, res)

    cnt = ord(s[at])
    for i in range(cnt):
        res = leggjaSaman(res, magic)

    return res

def taetaLykilord(s):
    return brengla(s, 0, True)


print(taetaLykilord('forrit123'))


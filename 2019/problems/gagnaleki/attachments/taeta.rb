
def heiltala(c)
    if "0" <= c and c <= "9"
        return c.ord - "0".ord
    end
    return c.ord - "a".ord + 10
end

def stafur(c)
    if 0 <= c and c <= 9
        return (c + "0".ord).chr
    end
    return ("a".ord + c - 10).chr
end

def leggjaSaman(a, b)
    carry = 0
    s = ""
    for at in (31).downto(0)
        carry += heiltala(a[at]) + heiltala(b[at])
        s = stafur(carry % 16) + s
        carry = carry / 16
    end
    return s
end

def brengla(s, at, u)
    magic = "b058592efd277ae75f27bd99d1628fbd"
    if at >= s.length
        return magic
    end

    res = leggjaSaman(brengla(s, at+1, true), brengla(s, at+1, false))
    for _ in 0..5
        res = leggjaSaman(res, res)
    end

    cnt = s[at].ord
    for _ in 0..cnt-1
        res = leggjaSaman(res, magic)
    end

    return res
end

def taetaLykilord(s)
    return brengla(s, 0, true)
end

puts taetaLykilord("forrit123")


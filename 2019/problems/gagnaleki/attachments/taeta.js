function heiltala(c) {
    if ('0' <= c && c <= '9') {
        return c.charCodeAt(0) - '0'.charCodeAt(0);
    }

    return c.charCodeAt(0) - 'a'.charCodeAt(0) + 10;
}

function stafur(c) {
    if (0 <= c && c <= 9) {
        return String.fromCharCode(c + '0'.charCodeAt(0));
    }

    return String.fromCharCode(c - 10 + 'a'.charCodeAt(0));
}

function leggjaSaman(a, b) {
    var carry = 0;
    var s = "";
    for (var at = 31; at >= 0; at--) {
        carry += heiltala(a.charAt(at)) + heiltala(b.charAt(at));
        s = stafur(carry % 16) + s;
        carry = Math.floor(carry / 16);
    }

    return s;
}

function brengla(s, at, u) {
    var magic = "b058592efd277ae75f27bd99d1628fbd";
    if (at >= s.length) {
        return magic;
    }

    var res = leggjaSaman(brengla(s, at+1, true), brengla(s, at+1, false));
    for (var i = 0; i < 6; i++) {
        res = leggjaSaman(res, res);
    }

    var cnt = s.charCodeAt(at);
    for (var i = 0; i < cnt; i++) {
        res = leggjaSaman(res, magic);
    }

    return res;
}

function taetaLykilord(s) {
    return brengla(s, 0, true);
}

putstr(taetaLykilord("forrit123") + "\n");


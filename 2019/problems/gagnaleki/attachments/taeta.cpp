#include <iostream>
#include <string>
using namespace std;

int heiltala(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    return c - 'a' + 10;
}

char stafur(int c) {
    if (0 <= c && c <= 9) {
        return c + '0';
    }
    return c - 10 + 'a';
}

string leggjaSaman(string a, string b) {
    int carry = 0;
    string s = "";
    for (int at = 31; at >= 0; at--) {
        carry += heiltala(a[at]) + heiltala(b[at]);
        s = string("") + stafur(carry % 16) + s;
        carry = carry / 16;
    }
    return s;
}

string brengla(string s, int at, bool u) {
    string magic = "b058592efd277ae75f27bd99d1628fbd";
    if (at >= (int)s.size()) {
        return magic;
    }

    string res = leggjaSaman(brengla(s, at+1, true), brengla(s, at+1, false));
    for (int i = 0; i < 6; i++) {
        res = leggjaSaman(res, res);
    }

    int cnt = s[at];
    for (int i = 0; i < cnt; i++) {
        res = leggjaSaman(res, magic);
    }

    return res;
}

string taetaLykilord(string s) {
    return brengla(s, 0, true);
}

int main() {
    cout << taetaLykilord("forrit123") << endl;

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi eratosthenes(int n) {
    vi p(n + 1, 1);
    for(int i = 2; i <= n; ++i) p[i] = i;
    for(int i = 2; i <= n; ++i) {
        if(p[i] != i) continue;
        if(i > 10000) continue;
        for(int j = i * i; j <= n; j += i) {
            p[j] = i;
        }
    }
    return p;
}

vi divisors(int x, vi &eratos) {
    if(x == 1) return vi({1});
    int p = eratos[x], e = 0;
    while(x % p == 0) x /= p, e++;
    vi result;
    for(int d : divisors(x, eratos)) {
        int pe = 1;
        for(int i = 0; i <= e; ++i) {
            result.push_back(d * pe);
            pe *= p;
        }
    }
    return result;
}

void try_add(int x, vi &p, set<int> &taken, vi &outp) {
    bool taxable = false;
    for(int d : divisors(x, p)) {
        if(d == x) continue;
        if(!taken.count(d)) {
            taken.insert(d);
            taxable = true;
        }
    }
    if(taxable) {
        taken.insert(x);
        outp.push_back(x);
    }
}

int main() {
    int n; cin >> n;
    vi p = eratosthenes(n);
    vi outp;
    set<int> taken;
    for(int i = n; i >= 0; --i) {
        if(p[i] == i) {
            try_add(i, p, taken, outp);
            break;
        }
    }
    taken.insert(outp[0]);
    taken.insert(1);
    for(int i = n; 2 * i > n; --i) {
        if(i % 2 == 0) continue;
        try_add(i, p, taken, outp);
    }
    for(int i = (n + 1) / 2; i <= n; ++i) {
        if(i % 2 == 1) continue;
        try_add(i, p, taken, outp);
    }
    cout << outp.size() << '\n';
    outp.pop_back();
    for(int x : outp) cout << x << ' ';
    cout << '\n';
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll egcd(ll a, ll b, ll& x, ll& y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = egcd(b, a % b, x, y);
  x -= a / b * y; swap(x, y); return d; }

ll mod_inv(ll a, ll m) {
  ll x, y, d = egcd(a, m, x, y);
  return d == 1 ? (x%m+m)%m : -1; }

struct Mod {
    ll x;
    Mod(ll _x = 0) {
        x = (_x % 1000000007 + 1000000007) % 1000000007;
    }
    Mod operator +(const Mod &other) const {
        return x + other.x;
    }
    Mod operator -(const Mod &other) const {
        return x - other.x;
    }
    Mod operator -() const {
        return -x;
    }
    Mod operator *(const Mod &other) const {
        return x * other.x;
    }
    Mod operator /(const Mod &other) const {
        return x * mod_inv(other.x, 1000000007);
    }
    Mod& operator -=(const Mod &other) {
        x = (*this - other).x;
        return *this;
    }
    bool operator ==(const Mod &other) const {
        return x == other.x;
    }
    bool operator !=(const Mod &other) const {
        return x != other.x;
    }
};
ostream& operator <<(ostream &outs, const Mod &x) {
    return outs << x.x;
}

typedef vector<Mod> vMod;
typedef vector<vMod> vvMod;

Mod matrix_rref(vvMod &M) {
    Mod det = Mod(1);
    int h = 0, k = 0;
    while(h < M.size() && k < M[0].size()) {
        int nonzind = -1;
        for(int i = h; i < M.size(); ++i) {
            if(M[i][k] != Mod(0)) {
                nonzind = i;
            }
        }
        if(nonzind == -1) {
            k++;
            det = 0;
        } else {
            std::swap(M[h], M[nonzind]);
            if(h != nonzind) det = -det;
            det = det * M[h][h];
            for(int i = h + 1; i < M.size(); ++i) {
                Mod f = M[i][k] / M[h][k];
                M[i][k] = Mod(0);
                for(int j = k + 1; j < M[0].size(); ++j) {
                    M[i][j] -= M[h][j] * f;
                }
            }
            h++;
            k++;
        }
    }
    return det;
}

typedef vector<vector<pair<Mod,int>>> ModGraph;

Mod calculate_resistance_exact(ModGraph &g, int x, int y) {
    if(x > y) {
        std::swap(x, y);
    }
    vvMod laplacian(g.size(), vMod(g.size(), Mod(0)));
    for(int i = 0; i < g.size(); ++i) {
        for(auto p : g[i]) {
            laplacian[i][p.second] -= Mod(1) / p.first;
        }
    }
    for(int i = 0; i < g.size(); ++i) {
        Mod sm = Mod(0);
        for(int j = 0; j < g.size(); ++j) {
            if(i == j) {
                continue;
            }
            sm -= laplacian[i][j];
        }
        laplacian[i][i] = sm;
    }
    vvMod cof11(g.size() - 1, vMod(g.size() - 1));
    vvMod cofxy(g.size() - 2, vMod(g.size() - 2));
    for(int i = 1; i < g.size(); ++i) {
        for(int j = 1; j < g.size(); ++j) {
            cof11[i - 1][j - 1] = laplacian[i][j];
        }
    }
    for(int i = 0; i < g.size(); ++i) {
        if(i == x || i == y) {
            continue;
        }
        int ind1 = i < x ? i : (i < y ? i - 1 : i - 2);
        for(int j = 0; j < g.size(); ++j) {
            if(j == x || j == y) {
                continue;
            }
            int ind2 = j < x ? j : (j < y ? j - 1 : j - 2);
            cofxy[ind1][ind2] = laplacian[i][j];
        }
    }
    return matrix_rref(cofxy) / matrix_rref(cof11);
}

int main() {
    int n, m, s, t, a, b, x;
    cin >> n >> m >> s >> t;
    s--; t--;
    ModGraph g(n);
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> x;
        a--; b--;
        g[a].push_back(make_pair(Mod(x), b));
        g[b].push_back(make_pair(Mod(x), a));
    }
    cout << calculate_resistance_exact(g, s, t).x << '\n';
}

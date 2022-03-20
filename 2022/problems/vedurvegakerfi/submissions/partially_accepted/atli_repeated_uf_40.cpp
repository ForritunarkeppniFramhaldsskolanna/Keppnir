#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct unionfind { 
  vi p; 
  int c;
  unionfind(int n) : p(n, -1), c(n) { }
  int find(int x) { 
    return p[x] < 0 ? x : p[x] = find(p[x]); 
  }
  bool united(int x, int y) { 
    return find(x) == find(y); 
  }
  void unite(int x, int y) { 
    int a = find(x), b = find(y);
    if(a == b) return; 
    if(p[a] > p[b]) swap(a, b);
    p[a] += p[b]; 
    p[b] = a; 
    c--; 
    return; 
  }
  int size(int x) { 
    return -p[find(x)]; 
  } 
};

int main() {
    int n, m, q, x = 0, aj, bj, hj; cin >> n >> m >> q;
    vi u(m), v(m), h(m); 
    for(int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> h[i];
        u[i]--; v[i]--;
    }
    for(int i = 0; i < q; ++i) {
        cin >> aj >> bj >> hj;
        aj ^= x; bj ^= x; hj ^= x;
        aj--; bj--;
        unionfind uf(n);
        for(int j = 0; j < m; ++j) {
            if(h[j] >= hj) {
                uf.unite(u[j], v[j]);
            }
        }
        if(uf.united(aj, bj)) {
            cout << "Jebb\n";
            x++;
        } else {
            cout << "Neibb\n";
        }
    }
}

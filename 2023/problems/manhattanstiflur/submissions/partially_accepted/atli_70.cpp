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
    int q, n, m, x1, y1, x2, y2;
    cin >> q >> n >> m;
    unionfind uf(n * m + 2);
    for(int i = 0; i < q; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x2 < x1) swap(x1, x2);
        if(y2 < y1) swap(y1, y2);
        if(y1 == y2) {
            if(y1 == 0) uf.unite(x1 * m + y1, n * m);
            else if(y1 == m) uf.unite(x1 * m + y1 - 1, n * m + 1);
            else uf.unite(x1 * m + y1 - 1, x1 * m + y1);
        } else {
            if(x1 == 0) uf.unite(x1 * m + y1, n * m + 1);
            else if(x1 == n) uf.unite((x1 - 1) * m + y1, n * m);
            else uf.unite((x1 - 1) * m + y1, x1 * m + y1);
        }
        if(uf.united(n * m, n * m + 1)) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct growing_unionfind { 
  vi p; map<int,int> ind;
  growing_unionfind() { }
  int find(int x) { 
    return p[x] < 0 ? x : p[x] = find(p[x]); 
  }
  bool united(int x, int y) { 
    if(!ind.count(x)) return false;
    if(!ind.count(y)) return false;
    return find(ind[x]) == find(ind[y]); 
  }
  void unite(int x, int y) { 
    if(!ind.count(x)) {
      ind[x] = p.size();
      p.push_back(-1);
    }
    if(!ind.count(y)) {
      ind[y] = p.size();
      p.push_back(-1);
    }
    int a = find(ind[x]), b = find(ind[y]);
    if(a == b) return; 
    if(p[a] > p[b]) swap(a, b);
    p[a] += p[b]; 
    p[b] = a; 
  }
  int size(int x) {
    if(!ind.count(x)) return 1;
    return -p[find(ind[x])]; 
  } 
};

int main() {
    int q, n, m, x1, y1, x2, y2;
    ios_base::sync_with_stdio(false);
    cin >> q >> n >> m;
    growing_unionfind uf;
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

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

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
    vvi edg(m, vi(3, 0));
    for(int i = 0; i < m; ++i) {
        cin >> edg[i][1] >> edg[i][2] >> edg[i][0];
        edg[i][1]--; edg[i][2]--;
    }
    sort(edg.begin(), edg.end());
    unionfind uf(n);
    for(int i = 0; i < q; ++i) {
        cin >> aj >> bj >> hj;
        aj ^= x; bj ^= x; hj ^= x;
        aj--; bj--;
        while(edg.size() > 0 && edg.back()[0] >= hj) {
            uf.unite(edg.back()[1], edg.back()[2]);
            edg.pop_back();
        }
        if(uf.united(aj, bj)) {
            cout << "Jebb\n";
            x++;
        } else {
            cout << "Neibb\n";
        }
    }
}

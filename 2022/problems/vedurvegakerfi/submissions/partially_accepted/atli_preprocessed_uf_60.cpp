#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct unionfind { 
  vi p;
  vector<list<int>> grps;
  int c;
  unionfind(int n) : p(n, -1), c(n), grps(n, list<int>()) {
    for(int i = 0; i < n; ++i) {
      grps[i].push_back(i);
    }
  }
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
    grps[a].splice(grps[a].end(), grps[b]);
    p[a] += p[b]; 
    p[b] = a; 
    c--; 
    return; 
  }
  int size(int x) { 
    return -p[find(x)]; 
  } 
  list<int> group(int x) {
    return grps[find(x)];
  }
};

int main() {
    int n, m, q, x = 0, aj, bj, hj; cin >> n >> m >> q;
    vvi edg(m, vi(3, 0));
    for(int i = 0; i < m; ++i) {
        cin >> edg[i][1] >> edg[i][2] >> edg[i][0];
        edg[i][1]--; edg[i][2]--;
    }
    sort(edg.rbegin(), edg.rend());
    vvi nd(n, vi(n, -1));
    unionfind uf(n);
    for(int i = 0; i < n; ++i) nd[i][i] = INT_MAX;
    for(int i = 0; i < m; ++i) {
        if(uf.united(edg[i][1], edg[i][2])) continue;
        for(int x : uf.group(edg[i][1])) {
            for(int y : uf.group(edg[i][2])) {
                nd[x][y] = nd[y][x] = edg[i][0];
            }
        }
        uf.unite(edg[i][1], edg[i][2]);
    }
    for(int i = 0; i < q; ++i) {
        cin >> aj >> bj >> hj;
        aj ^= x; bj ^= x; hj ^= x;
        aj--; bj--;
        if(nd[aj][bj] >= hj) {
            cout << "Jebb\n";
            x++;
        } else {
            cout << "Neibb\n";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct node {
  node *p, *jmp[20];
  int depth, ind;
  node(int _ind, node *_p = NULL) : p(_p), ind(_ind) {
    depth = p ? 1 + p->depth : 0;
    memset(jmp, 0, sizeof(jmp));
    jmp[0] = p;
    for (int i = 1; (1<<i) <= depth; i++)
      jmp[i] = jmp[i-1]->jmp[i-1]; } };
node* st[200000];
node* lca(node *a, node *b) {
  if (!a || !b) return NULL;
  if (a->depth < b->depth) swap(a,b);
  for (int j = 19; j >= 0; j--)
    while (a->depth - (1<<j) >= b->depth) a = a->jmp[j];
  if (a == b) return a;
  for (int j = 19; j >= 0; j--)
    while (a->depth >= (1<<j) && a->jmp[j] != b->jmp[j])
      a = a->jmp[j], b = b->jmp[j];
  return a->p; }

struct unionfind { 
  vi p, id;
  int c, idc;
  unionfind(int n) : p(n, -1), c(n), idc(n), id(n) {
    for(int i = 0; i < n; ++i) id[i] = i;
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
    p[a] += p[b]; 
    p[b] = a; 
    id[a] = idc++;
    c--; 
    return; 
  }
  int size(int x) { 
    return -p[find(x)]; 
  } 
  int grpid(int x) {
    return id[find(x)];
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
    unionfind uf(n);
    vi par(n, -1), id2w(n, INT_MAX);
    for(vi e : edg) {
        if(uf.united(e[1], e[2])) continue;
        par.push_back(-1);
        id2w.push_back(e[0]);
        int g1 = uf.grpid(e[1]), g2 = uf.grpid(e[2]);
        uf.unite(e[1], e[2]);
        par[g1] = uf.grpid(e[1]);
        par[g2] = uf.grpid(e[2]);
    }
    for(int i = par.size() - 1; i >= 0; --i) {
        node* nw = new node(i, par[i] == -1 ? NULL : st[par[i]]);
        st[i] = nw;
    }
    for(int i = 0; i < q; ++i) {
        cin >> aj >> bj >> hj;
        //aj ^= x; bj ^= x; hj ^= x;
        aj--; bj--;
        node* anc = lca(st[aj], st[bj]);
        if(id2w[anc->ind] >= hj) {
            cout << "Jebb\n";
            x++;
        } else {
            cout << "Neibb\n";
        }
    }
}

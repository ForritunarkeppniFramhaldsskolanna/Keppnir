#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

struct union_find {
	vi p;
	vi size;
	union_find(int n) : p(n) { 
		rep(i,0,n) p[i] = i; 
		size = vi(n);
		rep(i,0,n) size[i] = 1;
	}
	int find(int a) { 
		return p[a] == a ? a : p[a] = find(p[a]); 
	}
	bool joined(int a, int b) { 
		return find(a) == find(b);
	}
	int get_size(int a) {
		return size[find(a)];
	}
	void unite(int a, int b) { 
		if(joined(a,b)) return;
		size[find(b)] += size[find(a)];
		p[find(a)] = find(b); 
	}
};

int main() {
    cin.sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	union_find un(n);
	rep(i,0,q) {
		int t;
		cin >> t;
		if(t == 1) {
			int a,b;
			cin >> a >> b;
			a--;b--;
			un.unite(a,b);
		} else {
			int a;
			cin >> a;
			a--;
			cout << un.get_size(a)-1 << endl;
		
		}
	}
    return 0;
}



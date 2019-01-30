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

struct node {
	node* left = NULL;
	node* right = NULL;
	int sum, mx, mn, atr, atl;
	node(node* l, node* r, int v, int al, int ar) {
		left = l; right = r;
		sum = v; mx = v; mn = v;
		atl = al; atr = ar;
	}
	~node() {
		delete left;
		delete right;
	}
	void change(int at, int to) { // changes index of at into value of to
		if(at > atr || at < atl) return;
		if(at == atr && at == atl) {
			sum = to; mx = to; mn = to;
			return;
		}
		left->change(at,to);
		right->change(at,to);
		update();
	}
	void add(int at, int by) { // adds by to the index of at
		if(at > atr || at < atl) return;
		if(at == atr && at == atl) {
			sum+=by;mx+=by;mn+=by;
			return;
		}
		left->add(at,by);
		right->add(at,by);
		update();
	}
	void update() { // Changes everything when done
		sum = left->sum+right->sum;
		mn = min(left->mn, right->mn);
		mx = max(left->mx, right->mx);
	}
	int qsum(int l, int r) { // gets the some from range l to r
		if(l > atr || r < atl) return 0;
		if(l <= atl && atr <= r) return sum;
		return left->qsum(l,r)+right->qsum(l,r);
	}
	int qmn(int l, int r) { // gets the min value from l to r
		if(l > atr || r < atl) return INF;
		if(l <= atl && atr <= r) return mn;
		return min(left->qmn(l,r),right->qmn(l,r));
	}
	int qmx(int l, int r) { // gets the max value from l to r
		if(l > atr || r < atl) return 0;
		if(l <= atl && atr <= r) return mx;
		return max(left->qmx(l,r), right->qmx(l,r));
	}
};
node* build(int l, int r) {
	if(l > r) return NULL;
	if(l == r) return new node(NULL,NULL,0,l,r);
	int m = (l+r)/2;
	node* left = build(l,m);
	node* right = build(m+1,r);
	node* cur = new node(left,right,0,l,r);
	return cur;
}

int main() {
    cin.sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	bool rev = false;
	node *root = build(0,n-1);
	rep(i,0,q) {
		int t;
		cin >> t;
		if(t == 1) { // flip a single bit
			int at;
			cin >> at;
			at--;
			if(root->qsum(at,at) == 1) root->change(at,0);
			else root->change(at,1);
		} else if(t == 2) { // flip all da bits
			if(rev) rev = false;
			else rev = true;
		} else if(t == 3) { // ask how many bits are flipped
			ll total = root->qsum(0,n-1);
			if(rev) cout << n-total << endl;
			else cout << total << endl;
		} else { // ask how many bits are flipped in the range l to r
			ll l,r;
			cin >> l >> r;
			l--;r--;
			ll total = root->qsum(l,r);
			if(rev) cout << (r-l+1)-total << endl;
			else cout << total << endl;
		
		}
	}
	delete root;
    return 0;

}






















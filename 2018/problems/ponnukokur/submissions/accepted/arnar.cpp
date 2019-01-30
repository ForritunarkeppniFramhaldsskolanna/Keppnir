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

int main() {
    cin.sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
    int segsize = sqrt(n);
    int cnt = 0;
    vector<int> segcnt(n/segsize + 1, 0);
	vector<bool> pancakes(n, false);
    bool rev = false;
	rep(i,0,q) {
		int t;
		cin >> t;
		if(t == 1)
        { // flip a single bit
			int at;
			cin >> at;
			at--;
            if(pancakes[at]) segcnt[at/segsize]--, cnt--, pancakes[at] = false;
            else segcnt[at/segsize]++, cnt++, pancakes[at] = true;
		}
        else if(t == 2)
        { // flip all da bits
		    rev = !rev;
        }
        else if(t == 3) 
        { // ask how many bits are flipped
			if(rev) cout << n-cnt << endl;
			else cout << cnt << endl;
		}
        else
        { // ask how many bits are flipped in the range l to r
			int l,r;
			cin >> l >> r;
			l--;r--;
            int lseg = l/segsize, rseg = r/segsize;
            int total = 0;
            int j = l;
            while(j % segsize != 0 && j <= r) total += pancakes[j++];
            while(j + segsize <= r)
            {
                total += segcnt[j / segsize];
                j += segsize;
            }
            while(j <= r) total += pancakes[j++];
			if(rev) cout << (r-l+1) - total << endl;
			else cout << total << endl;
		
		}
	}
    return 0;

}






















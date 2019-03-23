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
    // This solution should be O(n^2) and should therefor get TLE
    int n,r,c;
    cin >> n  >> r >> c;
    vector<string> S1;
    vector<string> S2;
    rep(i,0,r) {
        S1.push_back("");
        S2.push_back("");
        rep(j,0,c) {
            string la;
            cin >> la;
            S1[i] += la;
        }
    }

    rep(i,0,r) {
        string le = "";
        rep(j,0,c) {
            string s;
            cin >> s;
            le += s;
        }
        if(le == S1[i]) cout << "left" << endl;
        else cout << "right" << endl;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main() {
    int n;
    cin >> n;
    map<string,int> cnt;
    rep(i,0,n) {
        string name, city;
        cin >> name >> city;
        cnt[city]++;
    }
    vector<pair<string,int> > res;
    iter(it,cnt) {
        res.push_back(*it);
    }
    random_shuffle(res.begin(), res.end());
    iter(it,res) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}


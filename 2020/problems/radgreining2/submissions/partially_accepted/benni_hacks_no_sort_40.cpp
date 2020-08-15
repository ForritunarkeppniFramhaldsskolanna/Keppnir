#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

typedef pair<int,string> is;
vector<is> K;
int n,m;
string s = "";
bool done = false;
clock_t at;

void backtrack(int at) {
    clock_t end = clock();
    double duration = (end-at) / (double) CLOCKS_PER_SEC;
    if(duration > 0.96) return;
    if(done) return;
    if(at >= m) {
        done = true;
        rep(i,0,n) {
            if(s[i] == '?') s[i] = 'C';
        }
        cout << s << endl;
        return;
    }
    // Don't flip
    int start = K[at].fs;
    string st = K[at].sc;
    bool good = true;
    rep(i,start, start+st.size()) {
        if(s[i] == '?') continue;
        if(s[i] != st[i-start]) good = false;
    }
    string old = s;
    if(good) {
        rep(i,start, start+st.size()) {
            s[i] = st[i-start];
        }
        backtrack(at+1);
    }

    s = old;

    if(done) return;


    // flip
    start = K[at].fs;
    st = K[at].sc;
    reverse(st.begin(), st.end());
    good = true;
    rep(i,start, start+st.size()) {
        if(s[i] == '?') continue;
        if(s[i] != st[i-start]) good = false;
    }
    old = s;
    if(good) {
        rep(i,start, start+st.size()) {
            s[i] = st[i-start];
        }
        backtrack(at+1);
    }

    s = old;
}



int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m;
    rep(i,0,n) s += "?";
    rep(i,0,m) {
        int start;
        string st;
        cin >> start >> st;
        K.pb(is(start-1,st));
    }
    // sort(K.rbegin(), K.rend());
    at = clock();
    backtrack(0);
    if(!done) {
        cout << "Villa" << endl;
    }


    return 0;
}



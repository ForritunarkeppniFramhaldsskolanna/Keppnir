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
int COLLISION[510][510];
int counter = 0;
int DONE[510];

void backtrack() {
    clock_t end = clock();
    double duration = (end-at) / (double) CLOCKS_PER_SEC;
    if(duration > 0.96) return;
    if(done) return;
    if(counter == m) {
        done = true;
        rep(i,0,n) {
            if(s[i] == '?') s[i] = 'C';
        }
        cout << s << endl;
        return;
    }
    int at = 0;
    rep(i,0,m) {
        if(!DONE[i]) at = i;
        rep(j,0,m) {
            if(DONE[j] && COLLISION[i][j]) break;
        }
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
        counter += 1;
        DONE[at] = true;
        backtrack();
        DONE[at] = false;
        counter -= 1;
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
        counter += 1;
        DONE[at] = true;
        backtrack();
        DONE[at] = false;
        counter -= 1;
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
    memset(COLLISION,0,sizeof(COLLISION));
    sort(K.rbegin(), K.rend());
    rep(i,0,m) {
        rep(j,0,m) {
            int l_1 = K[i].fs, r_1 = K[i].fs + K[i].sc.size();
            int l_2 = K[j].fs, r_2 = K[j].fs + K[j].sc.size();
            if(l_1 <= l_2 && l_2 <= r_1) COLLISION[i][j] = true;
            if(l_1 <= r_2 && r_2 <= r_1) COLLISION[i][j] = true;
        }
    }
    at = clock();
    backtrack();
    if(!done) {
        cout << "Villa" << endl;
    }


    return 0;
}



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

int main() {
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    vector<char> C;
    rep(i,0,s.size()) {
        if(s[i] == '.') continue;
        if(islower(s[i])) {
            C.pb(s[i]);
        } else {
            char want = tolower(s[i]);
            while(true) {
                if(C.size() == 0) {
                    cout << "Neibb" << endl;
                    return 0;
                }
                if(C.back() == want) {
                    C.pop_back();
                    break;
                } else {
                    C.pop_back();
                }
            }
        }
    }
    int p = 0;
    int g = 0;
    int o = 0;
    rep(i,0,C.size()) {
        if(C[i] == 'p') p++;
        if(C[i] == 'g') g++;
        if(C[i] == 'o') o++;
    }
    cout << p << endl;
    cout << g << endl;
    cout << o << endl;
    return 0;
}



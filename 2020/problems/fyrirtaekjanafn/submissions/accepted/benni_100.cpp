#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
    vector<string> K;
    string s;
    while(cin >> s) {
        string l = "";
        string T = "euoiaEUOIAyY";
        rep(i,0,s.size()) {
            bool good = false;
            rep(j,0,T.size()) {
                if(s[i] == T[j]) good = true;
            }
            if(good) l += s[i];
        }
        if(l.size() != 0) {
            K.pb(l);
        }
    }
    if(K.size() != 0) {
        cout << K[0];
        rep(i,1,K.size()) {
            cout << " " << K[i];
        }
    }
    cout << endl;
    return 0;
}



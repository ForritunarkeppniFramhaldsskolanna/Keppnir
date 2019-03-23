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
    int n;
    cin >> n;
    string s;
    getline(cin,s);
    rep(i,0,n) {
        getline(cin,s);
        rep(j,0,s.size()) {
            if(isalpha(s[j])) {
                s[j] = tolower(s[j]);
            }
        }
        rep(j,0,s.size()) {
            if(isalpha(s[j])) {
                s[j] = toupper(s[j]);
                break;
            }
        }
        cout << s << endl;
        
    }
    return 0;
}



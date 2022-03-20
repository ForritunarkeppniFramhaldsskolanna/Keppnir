#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define pb push_back
#define fs first
#define sc second
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const double EPS = 1e-9;

int main() {
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    bool contains = false;
    rep(i,0,(int)s.size() - 2) {
        if(s[i] == 'C' && s[i+1] == 'O' && s[i+2] == 'V') {
            contains = true;
        }
    }
    if(contains) {
        cout << "Veikur!" << endl;
    } else {
        cout << "Ekki veikur!" << endl;
    }
}


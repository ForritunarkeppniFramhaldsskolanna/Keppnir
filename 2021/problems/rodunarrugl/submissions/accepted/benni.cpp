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
    int n;
    cin >> n;
    vi A(n);
    rep(i,0,n) cin >> A[i], A[i]--;
    map<int,int> at;
    rep(i,0,n) at[A[i]] = i;
    int total = 0;
    set<int> D;
    rep(i,0,n) {
        if(A[i] != i && D.find(A[i]) == D.end()) {
            D.insert(A[i]);
            total++;
            int number = A[i];
            at[A[i]] = n;
            int pos = i;
            while(true) {
                int place = pos;
                if(number == place) {
                    total++;
                    break;
                }
                int was_at = at[pos];
                D.insert(pos);
                at[pos] = place;
                pos = was_at;
                total++;

            }
        }
    }
    cout << total << endl;
    return 0;
}



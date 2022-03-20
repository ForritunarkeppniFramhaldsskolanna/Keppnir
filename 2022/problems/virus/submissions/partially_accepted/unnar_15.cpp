#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

int calc(string s) {
  int cnt = 0, bst = 0;
  rep(i,0,s.size()){
    if(i > 0 && s[i] < s[i-1]) cnt = 0;
    cnt++;
    bst = max(bst, cnt);
  }
  return bst;
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  rep(i,0,n) {
    if (i > 1 && s[i] == s[i-1]) continue;
    rep(j, i+1, n) {
      string tmp = "";
      rep(k, 0, i){
        tmp += s[k];
        ans = max(ans, calc(tmp));
      }
      for (int k = j; k >= i; k--){
        tmp += s[k];
        ans = max(ans, calc(tmp));
      }
      rep(k, j+1, n){
        tmp += s[k];
        ans = max(ans, calc(tmp));
      }
    }
  }
  cout << ans << endl;
  return 0;
}

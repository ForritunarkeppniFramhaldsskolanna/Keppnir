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

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0, cnt2 = 0, cnt_same = 0, last = -1;
  vi dec(n), inc(n), compr(n+3, 0), rev(n);
  dec[0] = 1;
  int k = 0;
  rep(i,0,n) {
    if (s[i] > last) cnt = 0;
    if (s[i] < last) cnt2 = 0;
    if (i != 0 && s[i] != last) {
      k++;
      cnt_same = 0;
    }
    rev[i] = k;
    compr[k] = ++cnt_same;
    dec[i] = ++cnt;
    inc[i] = ++cnt2;
    last = s[i];
    //cout << dec [i] << " ";
  }
  //cout << endl;
  //rep(i,0,n) {
  //  cout << rev[i] << " ";
  //}
  //cout << endl;
  //rep(i,0,k+1) {
  //  cout << compr[i] << " ";
  //}
  //cout << endl;
  int ans = 0;  
  int mxDec = 0, mxInc = 0, mxOnes = 0, tmpInc = 0;
  for (int i = n-1; i >= 0; i--) { 
    int r = rev[i];
    if (s[i] == '1') {
      // flip this segment of ones to the segment of ones after it that is biggest (mx2)
      ans = max(ans, compr[r]+compr[r+1]+mxOnes);
      mxOnes = max(mxOnes, compr[r]);
      mxInc = max(mxInc, tmpInc);
      tmpInc = inc[i];
      i -= compr[r] - 1;
      continue;
    }
    // flip only the very next segment of zeros and ones as then you also gain the next segment of ones after it
    ans = max(ans, compr[r]+compr[r+1]+compr[r+2]+compr[r+3]);
    //cout << i << " " << r << " " << ans << endl;
    // flip the sequence behind this sequence of zeros to the best sequence of 1-0 after it
    //ans = max(ans, compr[r]+mxDec);
    // flip this sequence of zeros infront of the best sequence of 0-1 after it
    ans = max(ans, compr[r]+mxInc);
    // sacrifice this 0 to take the highest number of 1's after it instead
    if (r > 1) ans = max(ans, compr[r-1] + compr[r-2] + mxOnes);
    mxDec = max(mxDec, dec[i]);
    //cout << i << " " << ans << endl;
    i -= compr[r] - 1;
  }
  cout << ans << endl;
  return 0;
}

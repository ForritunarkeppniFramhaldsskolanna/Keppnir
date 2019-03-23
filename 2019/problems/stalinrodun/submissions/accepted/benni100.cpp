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

vi lis(vi arr) {
  if (arr.empty()) return vi();
  vi seq, back(size(arr)), ans;
  rep(i,0,size(arr)) {
    int res = 0, lo = 1, hi = size(seq);
    while (lo <= hi) {
      int mid = (lo+hi)/2;
      if (arr[seq[mid-1]] < arr[i]) res = mid, lo = mid + 1;
      else hi = mid - 1; }
    if (res < size(seq)) seq[res] = i;
    else seq.push_back(i);
    back[i] = res == 0 ? -1 : seq[res-1]; }
  int at = seq.back();
  while (at != -1) ans.push_back(at), at = back[at];
  reverse(ans.begin(), ans.end());
  return ans; }

int main() {
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    vi A(n);
    rep(i,0,n) cin >> A[i], A[i] *= -1;
    cout << lis(A).size() << endl;
    return 0;
}



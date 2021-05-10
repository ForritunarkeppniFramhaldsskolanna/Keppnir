#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

vi* adj;
bool* done;
int* owner;
int alternating_path(int left) {
  if (done[left]) return 0;
  done[left] = true;
  rep(i,0,adj[left].size()) {
    int right = adj[left][i];
    if (owner[right] == -1 ||
        alternating_path(owner[right])) {
      owner[right] = left; return 1; } }
  return 0; }

int main() {
    int n;
    cin >> n;

    adj = new vi[n];
    done = new bool[n];
    owner = new int[n];
    rep(i,0,n) owner[i] = -1;

    rep(i,0,n) {
        int cnt;
        cin >> cnt;
        rep(j,0,cnt) {
            int x;
            cin >> x;
            adj[i].push_back(x-1);
        }
    }

    int cnt = 0;
    rep(i,0,n) {
        rep(j,0,n) done[j] = false;
        cnt += alternating_path(i);
    }
    if (cnt < n) {
        cout << "Neibb" << endl;
        return 0;
    }
    rep(i,0,n) {
        if (i != 0) cout << " ";
        cout << owner[i]+1;
    }
    cout << endl;

    return 0;
}


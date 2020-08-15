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

int main() {
    cin.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<ll> > arr(n, vector<ll>(m));

    rep(i,0,n) {
        rep(j,0,m) {
            cin >> arr[i][j];
        }
    }

    int qs;
    cin >> qs;

    vector<vector<int> > vis(n, vector<int>(m, -1));

    rep(q,0,qs) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        priority_queue<pair<ll,ii>, vector<pair<ll,ii> >, greater<pair<ll,ii> > > pq;
        pq.push(make_pair(arr[a][b], ii(a,b)));
        vis[a][b] = q;

        ll mx = arr[a][b];
        while (true) {
            ii cur = pq.top().second;
            mx = max(mx, pq.top().first);
            pq.pop();

            if (cur.first == c && cur.second == d) {
                cout << mx << endl;
                break;
            }

            rep(di,-1,2) {
                rep(dj,-1,2) {
                    if (abs(di)+abs(dj) != 1) {
                        continue;
                    }
                    int ni = cur.first + di,
                        nj = cur.second + dj;
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && vis[ni][nj] < q) {
                        vis[ni][nj] = q;
                        pq.push(make_pair(arr[ni][nj], ii(ni,nj)));
                    }
                }
            }
        }
    }

    return 0;
}


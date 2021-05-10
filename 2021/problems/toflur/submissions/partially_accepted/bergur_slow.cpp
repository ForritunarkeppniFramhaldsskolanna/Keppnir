#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1LL << 60)
typedef long long ll;
using namespace std;

ll min(ll a, ll b) { return a < b ? a : b; }
ll sq(ll a) { return a*a; }

ll a[50], d[20][1 << 20], n;
ll foo(ll x, ll y)
{
	if (y == (1LL << n) - 1) return 0;
	if (d[x][y] != -1) return d[x][y];
	int i;
	d[x][y] = INF;
	rep(i, n) if ((y&(1 << i)) == 0) d[x][y] = min(d[x][y], sq(a[x] - a[i]) + foo(i, y + (1 << i)));
	return d[x][y];
}

int main()
{
	ll i, j, mn = INF;
    cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) rep(j, 1LL << n) d[i][j] = -1;
	rep(i, n) mn = min(mn, foo(i, (1LL << i)));
    cout << mn << endl;
	return 0;
}

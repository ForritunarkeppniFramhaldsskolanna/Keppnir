#include <bits/stdc++.h>

#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)

using namespace std;

int n, m, s, g, w;
vector<vector<int>> dist(20, vector<int>(20, 1'000'000'000));
vector<int> times(20);
unsigned int memo[20][1 << 20];

unsigned int dp(int at, int vis){
	if (vis == w) return 0;
	if (memo[at][vis]) return memo[at][vis];

	unsigned int mn = -1;
	rep(i, 1, n) {
		if ((vis & (1 << i)) == 0){
			mn = min(mn, dp(i, vis | (1 << i)) + dist[at][i]);
		}
	}
	return memo[at][vis] = mn;
}

void floyd_warshall(int n) {
  rep(k,0,n) rep(i,0,n) rep(j,0,n)
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(){
	cin >> n >> m >> s;
	memset(memo, 0, sizeof(memo));

	for (int i = 0; i < n; i++)
		w |= (1 << i);

	w ^= 1;

	int extra_time = 0;

	// Monsters
	rep(i, 0, n){
		cin >> times[i];
		extra_time += times[i];
	}

	// Shortest path
	rep(i, 0, m) {
		int from, to, l;
		cin >> from >> to >> l;
		from--;
		to--;
		dist[from][to] = l;
		dist[to][from] = l;
	}

	floyd_warshall(n);

	cout << dp(0, 0) + extra_time << endl;
}

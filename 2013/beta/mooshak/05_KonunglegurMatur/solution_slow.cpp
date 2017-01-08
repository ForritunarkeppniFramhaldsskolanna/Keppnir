#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T x) { return x.size(); }

// assert or gtfo

#define ok(x, y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < n && !visited[x][y])

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int n, x1, y1, x2, y2;
		scanf("%d %d %d %d %d\n", &n, &x1, &y1, &x2, &y2);
		x1--; x2--; y1--; y2--;
		bool** visited = new bool*[n];
		for (int i = 0; i < n; i++)
		{
			visited[i] = new bool[n];
			memset(visited[i], 0, n);
		}

		queue<pair<ii, int> > Q;
		Q.push(pair<ii, int>(ii(x1, y1), 0));
		visited[x1][y1] = true;

		int mnking, mnqueen;

		while (!Q.empty())
		{
			pair<ii, int> cur = Q.front(); Q.pop();
			if (cur.first.first == x2 && cur.first.second == y2)
			{
				mnking = cur.second;
				break;
			}

			int nx, ny;

			nx = cur.first.first + 0, ny = cur.first.second + 1;
			if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

			nx = cur.first.first + 0, ny = cur.first.second - 1;
			if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

			nx = cur.first.first + 1, ny = cur.first.second + 0;
			if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

			nx = cur.first.first + 1, ny = cur.first.second + 1;
			if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

			nx = cur.first.first + 1, ny = cur.first.second - 1;
			if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

			nx = cur.first.first - 1, ny = cur.first.second + 0;
			if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

			nx = cur.first.first - 1, ny = cur.first.second + 1;
			if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

			nx = cur.first.first - 1, ny = cur.first.second - 1;
			if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;
		}

		while (!Q.empty()) Q.pop();

		for (int i = 0; i < n; i++)
		{
			memset(visited[i], 0, n);
		}

		Q.push(pair<ii, int>(ii(x1, y1), 0));
		visited[x1][y1] = true;

		while (!Q.empty())
		{
			pair<ii, int> cur = Q.front(); Q.pop();
			if (cur.first.first == x2 && cur.first.second == y2)
			{
				mnqueen = cur.second;
				break;
			}

			int nx, ny;

			for (int l = 1; l <= n; l++)
			{
				nx = cur.first.first + 0 * l, ny = cur.first.second + 1 * l;
				if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

				nx = cur.first.first + 0 * l, ny = cur.first.second - 1 * l;
				if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

				nx = cur.first.first + 1 * l, ny = cur.first.second + 0 * l;
				if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

				nx = cur.first.first + 1 * l, ny = cur.first.second + 1 * l;
				if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

				nx = cur.first.first + 1 * l, ny = cur.first.second - 1 * l;
				if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

				nx = cur.first.first - 1 * l, ny = cur.first.second + 0 * l;
				if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

				nx = cur.first.first - 1 * l, ny = cur.first.second + 1 * l;
				if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;

				nx = cur.first.first - 1 * l, ny = cur.first.second - 1 * l;
				if (ok(nx, ny)) Q.push(pair<ii, int>(ii(nx, ny), cur.second + 1)), visited[nx][ny] = true;
			}
		}

		if (mnking < mnqueen)
		{
			printf("King\n");
		}
		else if (mnqueen < mnking)
		{
			printf("Queen\n");
		}
		else
		{
			printf("Same\n");
		}
	}

	return 0;
}
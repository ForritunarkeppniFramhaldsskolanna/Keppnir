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

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int l, n;
		scanf("%d %d\n", &l, &n);

		assert(0 <= l && l <= 10000);
		assert(1 <= n && n <= 1000);
		assert(n <= l + 1);

		int mn = -INF,
			mx = -INF;

		for (int i = 0; i < n; i++)
		{
			int cur;
			scanf("%d", &cur);

			assert(0 <= cur && cur <= l);

			mn = max(mn, min(cur, l - cur));
			mx = max(mx, max(cur, l - cur));
		}

		printf("%d %d\n", mn, mx);
	}

	return 0;
}
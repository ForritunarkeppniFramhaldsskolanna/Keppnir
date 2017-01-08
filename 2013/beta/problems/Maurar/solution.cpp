#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int l, n;
		scanf("%d %d\n", &l, &n);

		int mn = -INF,
			mx = -INF;

		for (int i = 0; i < n; i++)
		{
			int cur;
			scanf("%d", &cur);

			mn = max(mn, min(cur, l - cur));
			mx = max(mx, max(cur, l - cur));
		}

		printf("%d %d\n", mn, mx);
	}

	return 0;
}
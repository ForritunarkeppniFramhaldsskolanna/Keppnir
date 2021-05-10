#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
#define INF (1 << 30)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int main()
{
	int x, y, z, i, n, q;
	scanf("%d%d", &n, &q);
	int a[n];
	rep(i, n) scanf("%d", &a[i]);
	while (q--)
	{
		scanf("%d%d", &x, &y);
		z = x - 1;
		while (x < n && y > 0)
		{
			if (a[x] >= a[z]) y--, z = x;
			x++;
		}
		if (y == 0) printf("%d\n", x);
		else printf("leik lokid\n");
	}
	return 0;
}

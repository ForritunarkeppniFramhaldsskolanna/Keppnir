#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int i, j, x, y, z, n, q, r;
	scanf("%d%d", &n, &q);
	int a[n];
	rep(i, n) scanf("%d", &a[i]);
	while (q-- != 0)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) a[y - 1] = z;
		else if (x == 2)
		{
			r = a[y - 1];
			for (i = y; i < z; i++) r = gcd(r, a[i]);
			printf("%d\n", r);
		}
		else assert(0);
	}
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
#define INF (1 << 30)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

void nge(int* a, int* b, int n)
{
	int s[n], c = 0, i;
	rep(i, n)
	{
		while (c > 0 && a[s[c - 1]] <= a[i]) b[s[--c]] = i;
		s[c++] = i;
	}
	while (c > 0) b[s[--c]] = -1;
}

int main()
{
	int x, y, i, j, n, q, m = 18;
	scanf("%d%d", &n, &q);
	int a[n], b[m][n];
	rep(i, n) scanf("%d", &a[i]);
	nge(a, b[0], n);
	rep(i, m) rep(j, n) if (i != 0) b[i][j] = b[i - 1][j] == -1 ? -1 : b[i - 1][b[i - 1][j]];
	while (q--)
	{
		scanf("%d%d", &x, &y);
		x--;
		per(i, m) if (y >= (1 << i)) y -= (1 << i), x = (x == -1 ? -1 : b[i][x]);
		if (x != -1) printf("%d\n", x + 1);
		else printf("leik lokid\n");
	}
	return 0;
}

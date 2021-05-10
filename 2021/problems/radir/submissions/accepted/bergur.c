#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int main()
{
	int i, j, n, p, mn = INF;
	scanf("%d%d", &n, &p);
	int a[n], b[n], c[4][13];
	rep(i, n) scanf("%d%d", &a[i], &b[i]);
	rep(i, 4) rep(j, 13) c[i][j] = INF;
	rep(i, n) a[i]--, b[i]--;
	rep(i, n) c[a[i]][b[i]] = min(c[a[i]][b[i]], i);
	rep(i, 4) rep(j, 11) mn = min(mn, max(max(c[i][j], c[i][j + 1]), c[i][j + 2]));
	if (mn != INF) printf("%d\n", 1 + max(0, mn - p));
	else printf("Neibb\n");
	return 0;
}

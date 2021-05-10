#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int foo(int a, int b, int c)
{
	int x = min(min(a, b), c), y = a + b + c, z = max(max(a, b), c);
	return x + 1 == y - x - z && x + 2 == z;
}

int main()
{
	int i, j, k, n, p, mn = INF;
	scanf("%d%d", &n, &p);
	int a[n], b[n], r[n];
	rep(i, n) scanf("%d%d", &a[i], &b[i]);
	rep(i, n) r[i] = (i <= p ? 1 : r[i - 1] + 1);
	rep(i, n) rep(j, i) rep(k, j) if (a[i] == a[j] && a[j] == a[k] && foo(b[i], b[j], b[k])) mn = min(mn, max(max(r[i], r[j]), r[k]));
	if (mn != INF) printf("%d\n", mn);
	else printf("Neibb\n");
	return 0;
}

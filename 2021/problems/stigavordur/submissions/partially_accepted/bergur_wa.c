#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
int p[MAXN*5], n;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int qrec(int i, int j, int x, int y, int e) // Hjálparfall.
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	if (x == i && y == j) return p[e];
	int m = (i + j)/2;
	if (y <= m) return qrec(i, m, x, y, LEFT(e));
	if (x > m) return qrec(m + 1, j, x, y, RIGHT(e));
	return gcd(qrec(i, m, x, m, LEFT(e)), qrec(m + 1, j, m + 1, y, RIGHT(e)));
}
int query(int x, int y)
{ // Finnum summuna yfir [x, y].
	return qrec(0, n - 1, x, y, 1);
}

void urec(int i, int j, int x, int y, int e) // Hjálparfall.
{ // Við erum að leita að laufinu [x, x] og erum í [i, j].
	if (i == j) p[e] += y;
	else
	{
		int m = (i + j)/2;
		if (x <= m) urec(i, m, x, y, LEFT(e));
		else urec(m + 1, j, x, y, RIGHT(e));
		p[e] = gcd(p[LEFT(e)], p[RIGHT(e)]);
	}
}
void update(int x, int y)
{ // Bætum y við x-ta stakið.
	return urec(0, n - 1, x, y, 1);
}

int slow(int* a, int x, int y)
{ // Línuleg útfærsla til að bera saman.
	int r = 0;
	while (x <= y) r += a[x++];
	return r;
}

int main()
{
	int i, j, x, y, z, q;
	scanf("%d%d", &n, &q);
	rep(i, 5*n) p[i] = 0;
	rep(i, n)
	{
		scanf("%d", &x);
		update(i, x);
	}
	while (q-- != 0)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) update(y - 1, z);
		else if (x == 2) printf("%d\n", query(y - 1, z - 1));
		else assert(0);
	}
	return 0;
}

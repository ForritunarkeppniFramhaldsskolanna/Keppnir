#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
 
int mabs(int a) { if (a > 0) { return a; } return -a; }
int min(int a, int b) { if (a > b) { return b; } return a; }
int max(int a, int b) { if (a < b) { return b; } return a; }
int get_int();
int foo(int a, int b, int c, int d)
{
	if (a == 1 && d == 1) return 1;
	if (b == 1 && c == 1) return 1;
	if (a == 1 && b == 1) return 1;
	if (c == 1 && d == 1) return 1;
	return 0;
}

int main()
{
	int ii, i, j, n = get_int(), q = get_int();
	int k = 1;
	while (k*k < n) k++;
	int a[k][2][k], b[k];
	rep(i, k) rep(j, k) a[i][0][j] = a[i][1][j] = 0;
	rep(i, k) b[i] = 1;
	int e = 0;
	rep(i, n) if (getchar() == 'o') a[i/k][0][i%k] = 1 - a[i/k][0][i%k];
	getchar();
	rep(i, n) if (getchar() == 'o') a[i/k][1][i%k] = 1 - a[i/k][1][i%k];
	getchar();

	rep(i, k)
	{
		rep(j, k - 1) if (foo(a[i][0][j], a[i][1][j], a[i][0][j + 1], a[i][1][j + 1])) break;
		b[i] = (j < k - 1) ? 0 : 1;
	}
	rep(i, k - 1) if (foo(a[i][0][k - 1], a[i][1][k - 1], a[i + 1][0][0], a[i + 1][1][0])) break;
	rep(j, k) if (b[j] == 0) break;
	e = j < k || i < k - 1;

	while (q-- != 0)
	{
		char c = getchar();
		if (c == 'U')
		{
			int x = get_int() - 1, y = get_int() - 1;
			a[y/k][x][y%k] = 1 - a[y/k][x][y%k];
			rep(i, k - 1) if (foo(a[y/k][0][i], a[y/k][1][i], a[y/k][0][i + 1], a[y/k][1][i + 1])) break;
			b[y/k] = i < k - 1 ? 0 : 1;
			rep(i, k - 1) if (foo(a[i][0][k - 1], a[i][1][k - 1], a[i + 1][0][0], a[i + 1][1][0])) break;
			rep(j, k) if (b[j] == 0) break;
			e = j < k || i < k - 1;
		}
		else getchar(), printf("%s\n", e ? "Neibb" : "Jebb");
	}
	return 0;
}

int get_int()
{
	int sgn = 1, ret = 0;
	char c  = getchar();
	while (1)
	{
		if (c == EOF) return EOF;
		if (c >= '0' && c <= '9') break;
		if (c == '-')
		{
			c = getchar();
			if (c < '0' || c > '9') continue;
			sgn = -1;
			break;
		}
		c = getchar();
	}

	while (1)
	{
		ret = ret*10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') return sgn*ret;
	}
}

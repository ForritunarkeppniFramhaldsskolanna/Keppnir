#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int get_int();
int n, k,
	d[1000][1000],
	e[1000][1000],
	f[1000][1000],
	x[1000][1000],
	y[1000][1000],
	a[1000][1000];
int goo(int x, int y)
{
	if (x >= n || y >= n) return 0;
	if (e[x][y] != -1) return e[x][y];
	return e[x][y] = goo(x + 1, y) + (a[x][y] > 0 ? a[x][y] : 0);
}
int hoo(int x, int y)
{
	if (x >= n || y >= n) return 0;
	if (f[x][y] != -1) return f[x][y];
	return f[x][y] = hoo(x, y + 1) + (a[x][y] > 0 ? a[x][y] : 0);
}
int foo(int x, int y)
{
	if (x >= n || y >= n) return 0;
	if (d[x][y] != -1) return d[x][y];
	return d[x][y] = goo(x + 1, y) + hoo(x, y + 1) + foo(x + 1, y + 1) + (a[x][y] > 0 ? a[x][y] : 0);
}

int main()
{
	int i, j, l;
	n = get_int(), k = get_int();
	rep(i, n) rep(j, n) x[i][j] = y[i][j] = 0;
	rep(i, n) rep(j, n) d[i][j] = e[i][j] = f[i][j] = -1;
	rep(i, n)
	{
		rep(j, n) 
		{
			a[i][j] = getchar();
			if (a[i][j] == '.') a[i][j] = 0;
			else if (a[i][j] == '#') a[i][j] = -1;
			else a[i][j] -= '0';
		}
		getchar();
	}

	rep(l, n)
	{
		i = 0;
		while (i < n)
		{
			while (i < n && a[l][i] != 0) i++;
			if (i == n) break;
			j = i;
			while (j < n && j - i + 1 < k && a[l][j] == 0) j++;
			while (j < n && a[l][j] == 0) x[l][j++ - k + 1] = 1; 
			i = j;
		}
	}
	rep(l, n)
	{
		i = 0;
		while (i < n)
		{
			while (i < n && a[i][l] != 0) i++;
			if (i == n) break;
			j = i;
			while (j < n && j - i + 1 < k && a[j][l] == 0) j++;
			while (j < n && a[j][l] == 0) y[j++ - k + 1][l] = 1; 
			i = j;
		}
	}
	int mx = 0;
	rep(i, n - k + 1) rep(j, n - k + 1) if (x[i][j] && y[i][j] && x[i + k - 1][j] && y[i][j + k - 1])
		mx = max(mx, foo(i, j) - foo(i + k, j) - foo(i, j + k) + foo(i + k, j + k));
	printf("%d\n", mx);
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

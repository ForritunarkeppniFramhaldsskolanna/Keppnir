#include <stdlib.h>
#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
void foo(int* a, int* b, int n)
{
	int s1[n], s2[n], c = 0, i;
	for (i = 0; i < n; i++)
	{
		while (c > 0 && s1[c - 1] > a[i]) b[s2[--c]] = i;
		s1[c] = a[i], s2[c] = i; c++;
	}
	while (c > 0) b[s2[--c]] = -1;
}

int main()
{
	int n = get_int(), m = get_int(), i, j;
	int a[n], b[n], c[n], d[n], e[n], f[n];
	rep(i, n) a[i] = get_int() - 1;
	rep(i, m) get_int();
	rep(i, n) b[i] = get_int() - 1;
	rep(i, n) c[a[i]] = i;
	rep(i, n) d[i] = c[b[i]];
	foo(d, e, n);
	rep(i, n) f[i] = 0;
	rep(i, n - 1) f[b[e[i]]]++;
	int** o = malloc(sizeof(int*)*n);
	rep(i, n) o[i] = malloc(sizeof(int)*f[i]);
	rep(i, n) f[i] = 0;
	rep(i, n - 1) o[b[e[i]]][f[b[e[i]]]++] = b[i];
	rep(i, n) { printf("%d: ", i + 1); rep(j, f[i]) printf("%d ", o[i][j] + 1); printf("\n"); }
	rep(i, n) free(o[i]);
	free(o);
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

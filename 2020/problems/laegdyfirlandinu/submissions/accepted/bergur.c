#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();

int main()
{
	int i, j, n = get_int(), m = get_int();
	int a[n][m];
	rep(i, n) rep(j, m) a[i][j] = get_int();
	for (i = 1; i < n - 1; i++) for (j = 1; j < m - 1; j++)
	{
		if (a[i][j] < a[i - 1][j] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1])
		{
			printf("Jebb\n");
			return 0;
		}
	}
	printf("Neibb\n");
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

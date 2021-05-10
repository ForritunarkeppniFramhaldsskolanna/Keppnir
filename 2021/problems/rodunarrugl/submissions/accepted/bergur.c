#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
int main()
{
	int n = get_int(), i, r = 0;
	int a[n], b[n];
	rep(i, n) a[i] = get_int() - 1;
	rep(i, n) b[i] = 0;
	rep(i, n) if (b[i] == 0 && a[i] != i)
	{
		r++;
		int x = i;
		while (b[x] == 0)
		{
			r++;
			b[x] = 1;
			x = a[x];
		}
	}
	printf("%d\n", r);
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

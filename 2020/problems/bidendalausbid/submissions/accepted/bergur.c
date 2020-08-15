#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();

int main()
{
	int a = get_int(), b = get_int(), c = get_int(), d = get_int();
	a = a*60 + b, b = c*60 + d;
	printf("%d\n", b - a + (b < a ? 24*60 : 0));
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

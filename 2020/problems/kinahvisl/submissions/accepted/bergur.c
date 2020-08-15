#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
int main()
{
	char s[2][1000001];
	int i, r = 1;
	i = 0; do s[0][i++] = getchar(); while (s[0][i - 1] != 10);
	i = 0; do s[1][i++] = getchar(); while (s[1][i - 1] != 10);
	for (i = 0; s[0][i] != 10; i++) r += s[0][i] == s[1][i] ? 0 : 1;
	printf("%d\n", r);
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

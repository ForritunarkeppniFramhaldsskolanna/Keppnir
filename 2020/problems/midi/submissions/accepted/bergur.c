#include <stdio.h>
#define getchar() fgetc_unlocked(stdin)
int get_int();

int main()
{
	char s[2000001];
	int n = get_int(), m = 2000000;
	s[m--] = '\0';
	while (n-- != 0)
	{
		char c = getchar();
		while (c != 10) { s[m--] = c; c = getchar(); }
	}
	printf("%s\n", s + m + 1);
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

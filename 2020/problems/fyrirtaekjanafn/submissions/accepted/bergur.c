#include <stdio.h>
typedef long long ll;
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { return a < b ? a : b; }

int get_int();

int foo(char c) { return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'y'; }
int main()
{
	for (char c = getchar(); c != 10; c = getchar()) if (foo(c >= 'a' && c <= 'z' ? c : c - 'A' + 'a')) putchar(c);
	putchar(10);
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

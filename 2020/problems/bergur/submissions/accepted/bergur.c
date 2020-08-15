#include <stdio.h>
typedef long long ll;
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { return a < b ? a : b; }

int get_int();

int main()
{
	ll i, n = get_int(), r = 0, l = 1000000;
	ll a[n];
	rep(i, n) a[i] = get_int();
	rep(i, n) r += l = min(l, a[n - 1 - i]);
	printf("%lld\n", r);
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

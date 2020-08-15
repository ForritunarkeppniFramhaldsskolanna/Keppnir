// O(m)
#include <stdio.h>
typedef __int128 ll;
#define rep(E, F) for (E = 0; E < (F); E++)
ll get_int();
#define smod(E) (((E)%m + m)%m)
#define foo(E) (smod(smod(E*a) + b))

int main()
{
	ll a = get_int(), b = get_int(), x = get_int(), n = get_int(), m = get_int();
	ll i, g[m], l = 1;
	rep(i, m) g[i] = 0;
	x = foo(x);
	while (g[x] == 0 && l < n)
	{
		g[x] = l++;
		x = foo(x);
	}
	if (l < n)
	{
		ll h = (n - l)%(l - g[x]);
		rep(i, h) x = foo(x);
	}
	printf("%lld\n", x);
	return 0;
}

ll get_int()
{
	ll sgn = 1, ret = 0;
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

// O(ln x)
#include <stdio.h>
typedef long long ll;
#define rep(E, F) for (E = 0; E < (F); E++)
ll get_int();
#define smod(E) (((E)%mm + mm)%mm)

ll mm;
// 1 + a + a^2 + ... a^y
// g = a^y
ll foo(ll x, ll y, ll* g)
{
	if (y == 0) { *g = 1; return 1; }
	if (y == 1) { *g = x; return smod(1 + x); }
	if (y%2 == 0)
	{
		ll r = foo(x, y/2 - 1, g);
		r = smod(r + smod(smod(*g*x)*r));
		*g = smod(*g*x);
		*g = smod(*g**g);
		r = smod(r + *g);
		return r;
	}
	else
	{
		ll r = foo(x, y/2, g);
		r = smod(r + smod(smod(*g*x)*r));
		*g = smod(*g**g);
		*g = smod(*g*x);
		return r;
	}
}

int main()
{
	ll a = get_int(), b = get_int(), x = get_int(), n = get_int(), m = get_int(), g;
	mm = m;
	ll r = foo(a, n - 1, &g);
	printf("%lld\n", smod(smod(smod(g*a)*x) + smod(b*r)));
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

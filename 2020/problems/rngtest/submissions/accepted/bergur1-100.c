// O(ln^2 x)
#include <stdio.h>
typedef long long ll;
#define rep(E, F) for (E = 0; E < (F); E++)
ll get_int();
#define smod(E) (((E)%mm + mm)%mm)

ll mm;
ll goo(ll x, ll y)
{
	ll r;
	for (r = 1; y > 0; y /= 2)
	{
		if (y&1) r = smod(r*x);
		x = smod(x*x);
	}
	return r;
}
// 1 + a + a^2 + ... a^y
// g = a^y
ll foo(ll x, ll y, ll* g)
{
	if (y == 0) { *g = 1; return 1; }
	if (y == 1) { *g = x; return smod(1 + x); }
	ll r = foo(x, (y - 1)/2, g);
	if (y%2 == 1) r = smod(r + smod(goo(x, (y + 1)/2)*r));
	else r = smod(smod(r + smod(goo(x, y/2)*r)) + goo(x, y));
	return r;
}

int main()
{
	ll a = get_int(), b = get_int(), x = get_int(), n = get_int(), m = get_int(), g;
	mm = m;
	ll r = foo(a, n - 1, &g);
	printf("%lld\n", smod(smod(goo(a, n)*x) + smod(b*r)));
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

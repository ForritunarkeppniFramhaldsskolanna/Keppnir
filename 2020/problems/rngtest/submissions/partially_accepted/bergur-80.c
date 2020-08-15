// O(ln n)
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

ll foo(ll x) { return goo(x, mm - 2); }

int main()
{
	ll a = get_int(), b = get_int(), x = get_int(), n = get_int(), m = get_int();
	mm = m;
	printf("%lld\n", smod(smod(x*goo(a, n)) + smod(smod(b*(1 - goo(a, n)))*foo(1 - a))));
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

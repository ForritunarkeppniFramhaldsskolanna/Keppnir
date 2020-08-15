#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
typedef long long ll;
ll get_int();

ll gcd(ll a, ll b)
{
	ll r;
	while (b > 0) { r = a%b; a = b; b = r; }
	return a;
}

int main()
{
	ll i, n = get_int(), d = get_int(), r = 0;
	ll a[n];
	rep(i, n) a[i] = get_int();
	i = 0;
	while (a[i] > 0)
	{
		r += a[i];
		a[i] = -1;
		i = (i + d)%n;
	}
	printf("%lld\n", r);
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

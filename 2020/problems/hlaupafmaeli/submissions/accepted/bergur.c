#include <stdio.h>
typedef long long ll;
#define rep(E, F) for (E = 0; E < (F); E++)
ll get_int();

int foo(ll n)
{
	return n%4 == 0 && (n%100 != 0 || n%400 == 0);
}

int main()
{
	ll n = get_int();
	if (!foo(n)) printf("Neibb\n");
	else printf("%lld\n",  n/4 - n/100 + n/400 - (2020/4 - 2020/100 + 2020/400));
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

#include <stdio.h>
typedef long long ll;
ll get_int();

double poww(double x, ll y)
{
	double r = 1.0;
	while (y > 0)
	{
		if (y%2) r *= x;
		y /= 2;
		x = x*x;
	}
	return r;
}

int main()
{
	ll d = get_int(), k = get_int();
	printf("%.8f\n", d*(1 - poww(0.5, k + 1))/0.5);
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

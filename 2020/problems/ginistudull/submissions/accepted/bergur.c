#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
int cmp(const void* p1, const void* p2)
{
	if (*(ll*)p1 > *(ll*)p2) return 1;
	if (*(ll*)p1 < *(ll*)p2) return -1;
	return 0;
}

int main()
{
	ll i, j, n = get_int(), t = 0;
	ll a[n];
	rep(i, n) a[i] = get_int();
	rep(i, n) t += a[i];
	double s = 1.0/(2*n*t), r = 0.0;
	qsort(a, n, sizeof(a[0]), cmp);
	rep(i, n)
	{
		t -= a[i];
		r += t - (n - 1 - i)*a[i];
	}
	r *= 2;
	printf("%.8f\n", s*r);
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

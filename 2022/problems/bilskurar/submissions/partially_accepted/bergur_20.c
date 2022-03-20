// prófar random pör og dregur ályktun útfrá hlutfallinu.
#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
#define rep(E, F) for (E = 0; E < (F); E++)
ll get_int()
{
	ll r = 0, c = getchar(), s = 1;
	while (c != '-' && c < '0' || c > '9') c = getchar();
	while (c == '-') s *= -1, c = getchar();
	while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
	return s*r;
}

int main()
{
	srand(69420);
	ll i, x, y, n = get_int(), a[n], b[n], p = 0, q = 1 << 20;
	rep(i, n) a[get_int() - 1] = i;
	rep(i, n) b[get_int() - 1] = i;
	rep(i, q)
	{
		x = rand()%n, y = rand()%n;
		while (x == y) x = rand()%n, y = rand()%n;
		p += (a[x] < a[y]) != (b[x] < b[y]);
	}
	printf("%lld\n", (ll)(0.5*n*(n - 1)*p/q + 0.5));
	return 0;
}

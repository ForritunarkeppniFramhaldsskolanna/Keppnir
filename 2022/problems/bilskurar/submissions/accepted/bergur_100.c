#include <stdio.h>
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

ll sum(ll *a, ll i)
{ // [0, i]
    ll r = 0;
	for (i++; i > 0; i -= (i&-i)) r += a[i];
    return r;
}

void add(ll *a, ll i, ll k)
{
	for (i++; i <= a[0]; i += (i&-i)) a[i] += k;
}

void init(ll *a, ll n)
{
	ll i;
	rep(i, n) a[i + 1] = 0;
	a[0] = n;
}

int main()
{
	ll i, n = get_int(), a[n], b[n], f[n + 1], r = 0;
	init(f, n);
	rep(i, n) a[get_int() - 1] = i;
	rep(i, n) b[i] = a[get_int() - 1];
	rep(i, n) add(f, i, 1);
	rep(i, n) add(f, b[i], -1), r += sum(f, b[i]);
	printf("%lld\n", r);
	return 0;
}

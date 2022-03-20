#pragma GCC optimize("O3")
#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int()
{
	int r, c;
	for (r = 0, c = fgetc_unlocked(stdin); '0' <= c && c <= '9'; c = fgetc_unlocked(stdin)) r = r*10 + c - '0';
	return r;
}

int main()
{
    int i, j, n = get_int(), a[n], b[n], c[n], d[n];
	rep(i, n) a[get_int() - 1] = i;
	rep(i, n) b[get_int() - 1] = i;
    long long r = 0;
	rep(i, n) for (j = i + 1; j < n; j++)  r += (a[j] < a[i]) != (b[j] < b[i]);
	printf("%lld\n", r);
	return 0;
}

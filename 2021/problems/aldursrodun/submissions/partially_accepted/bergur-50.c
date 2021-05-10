#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int get_int()
{
	int r = 0, c = getchar();
	if (c == '-') return -get_int();
	if (c < '0' || c > '9') return get_int();
	for (; c >= '0' && c <= '9'; c = getchar()) r = r*10 + c - '0';
	return r;
}

int gcd(int a, int b)
{
	if (a < b) return gcd(b, a);
	int x = b;
	while (x > 1 && (a%x || b%x)) x--;
	return x;
}

int foo(int a, int b, int c)
{
	if (gcd(a, b) == 1) return 0;
	if (gcd(b, c) == 1) return 0;
	printf("%d %d %d\n", a, b, c);
	return 1;
}

int main()
{
	int i, n = get_int(), x = get_int(), y = get_int(), z = get_int();
	if (foo(x, y, z));
	else if (foo(x, z, y));
	else if (foo(y, x, z));
	else if (foo(y, z, x));
	else if (foo(z, x, y));
	else if (foo(z, y, x));
	else printf("neibb\n");
	return 0;
}

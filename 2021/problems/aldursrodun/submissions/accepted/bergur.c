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
	while (b > 0) { int r = a%b; a = b; b = r; }
	return a;
}

int f[10], b[10], a[10], e = 0;
void foo(int x, int n)
{
	int i;
	if (x == n)
	{
		if (e) return;
		rep(i, n - 1) if (gcd(a[b[i]], a[b[i + 1]]) == 1) break;
		if (i < n - 1) return;
		rep(i, n) printf("%d ", a[b[i]]);
		printf("\n");
		e = 1;
		return;
	}
	rep(i, n) if (!f[i])
	{
		b[x] = i;
		f[i] = 1;
		foo(x + 1, n);
		f[i] = 0;
	}
}

int main()
{
	int i, n = get_int();
	rep(i, n) a[i] = get_int();
	rep(i, n) f[i] = 0;
	foo(0, n);
	if (!e) printf("neibb\n");
	return 0;
}

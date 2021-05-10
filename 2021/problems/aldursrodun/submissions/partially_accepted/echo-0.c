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

int main()
{
	int i, n = get_int();
	rep(i, n) printf("%d ", get_int());
	printf("\n");
	return 0;
}

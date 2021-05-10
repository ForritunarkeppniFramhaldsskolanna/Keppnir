#include <stdlib.h>
#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	int a[n];
	rep(i, n) scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);
	int r = 0;
	rep(i, n - 1) r = r + 1LL*(a[i + 1] - a[i])*(a[i + 1] - a[i]);
	printf("%lld\n", r);
	return 0;
}

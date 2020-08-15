#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n = 100000;
	int i, m = 1000000000/n;
	int a[n];
	a[0] = rand()%99 + 1;
	for (i = 1; i < n; i++) do { a[i] = rand()%99 + 1; } while (a[i - 1] == a[i]);
	printf("%d %d\n", n, n);
	for (i = 0; i < n - 1; i++) printf("%d %d\n", a[i], (i + 1)*m);
	printf("%d\n", a[n - 1]);
	for (i = 0; i < n/2; i++) { int t = a[2*i]; a[2*i] = a[2*i + 1]; a[2*i + 1] = t; }
	for (i = 0; i < n - 1; i++) printf("%d %d\n", a[i], (i + 1)*m);
	printf("%d\n", a[n - 1]);
}

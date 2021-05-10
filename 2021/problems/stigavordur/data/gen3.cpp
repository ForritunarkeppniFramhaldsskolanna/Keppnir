#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int f[13], m = 8, k = 5, n;
int number()
{
	return f[rand()%m + k];
}

int query()
{
	return rand()%2 + 1;
}

int ind()
{
	return rand()%n + 1;
}

int main(int argc, char** argv)
{
	if (argc == 3) srand(time(NULL));
	else if (argc == 4) srand(atoi(argv[3]));
	else assert(0);
	int i, q = atoi(argv[2]);
	n = atoi(argv[1]);
	f[0] = 1;
	rep(i, 13) if (i != 0) f[i] = f[i - 1]*i;
	printf("%d %d\n", n, q);
	rep(i, n - 1) printf("%d ", number());
	printf("%d\n", number());
	rep(i, q)
	{
		int x = query(), y = ind(), z = ind();
		if (x == 1) printf("%d %d %d\n", x, ind(), number());
		else printf("%d %d %d\n", x, min(y, z), max(y, z));
	}
	return 0;
}

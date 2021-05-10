#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int main(int argc, char** argv)
{
	if (argc == 4) srand(time(NULL));
	else if (argc == 5) srand(atoi(argv[4]));
	else assert(0);
	int i, n = atoi(argv[1]), q = atoi(argv[2]), m = atoi(argv[3]);
	printf("%d %d\n", n, q);
	rep(i, n - 1) printf("%d ", rand()%m + 1);
	printf("%d\n", rand()%m + 1);
	rep(i, q)
	{
		int x = rand()%2 + 1, y = rand()%n + 1, z = rand()%n + 1;
		if (x == 1) printf("%d %d %d\n", x, rand()%n + 1, rand()%m + 1);
		else printf("%d %d %d\n", x, min(y, z), max(y, z));
	}
	return 0;
}

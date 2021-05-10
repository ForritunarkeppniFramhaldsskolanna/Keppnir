#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int main(int argc, char** argv)
{ // Generates stuff.
	if (argc == 4) srand(time(NULL));
	else if (argc == 5) srand(atoi(argv[4]));
	else assert(0);
	int i, n = atoi(argv[1]), q = atoi(argv[2]), m = atoi(argv[3]);
	printf("%d %d\n", n, q);
	rep(i, n - 1) printf("%d ", rand()%1000000000 + 1); printf("%d\n", rand()%1000000000 + 1);
	rep(i, q) printf("%d %d\n", rand()%n + 1, rand()%m + 1);
	return 0;
}

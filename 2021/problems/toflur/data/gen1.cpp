#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int main(int argc, char** argv)
{ // Generates |n| random tiles.
	if (argc == 2) srand(time(NULL));
	else if (argc == 3) srand(atoi(argv[2]));
	else assert(0);
	int i, n = atoi(argv[1]);
	printf("%d\n", n);
	rep(i, n - 1) printf("%d ", rand()%1000000 + 1); printf("%d\n", rand()%1000000 + 1);
	return 0;
}

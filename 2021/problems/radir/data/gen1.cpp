#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int main(int argc, char** argv)
{ // Generates |n| random cards with given |p|.
	if (argc == 3) srand(time(NULL));
	else if (argc == 4) srand(atoi(argv[3]));
	else assert(0);
	int i, n = atoi(argv[1]), p = atoi(argv[2]);
	printf("%d %d\n", n, p);
	rep(i, n) printf("%d %d\n", rand()%4 + 1, rand()%13 + 1);
	return 0;
}

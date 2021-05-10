#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int main(int argc, char** argv)
{ // All queries.
	int i;
	if (argc == 3) srand(time(NULL));
	else if (argc == 4) srand(atoi(argv[3]));
	else assert(0);

	int n = atoi(argv[1]), q = atoi(argv[2]), f[2] = {433494437, 701408733};

	printf("%d %d\n", n, q);
	rep(i, n - 1) printf("%d ", f[i%2]);
	printf("%d\n", f[i%2]);
	rep(i, q)
	{
		int y = rand()%n + 1, z = rand()%n + 1;
		printf("2 %d %d\n", min(y, z), max(y, z));
	}
	return 0;
}

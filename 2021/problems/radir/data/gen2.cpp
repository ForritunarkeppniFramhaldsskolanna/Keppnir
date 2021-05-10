#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int main(int argc, char** argv)
{ // Generates |n| random cards with given |p| and makes sure that the answer is either ``neibb'' or larger than |t| - |p|.
	if (argc == 4) srand(time(NULL));
	else if (argc == 5) srand(atoi(argv[4]));
	else assert(0);
	int i, j, k, n = atoi(argv[1]), p = atoi(argv[2]), t = atoi(argv[3]), c[4][13];
	rep(i, 4) rep(j, 13) c[i][j] = 0;
	printf("%d %d\n", n, p);
	rep(i, n)
	{
		int x, y;
		while (1)
		{
			x = rand()%4, y = rand()%13;
			if (i > t) break;
			if (y <= 10 && c[x][y + 1] && c[x][y + 2]) continue;
			if (y <= 11 && y >= 1 && c[x][y - 1] && c[x][y + 1]) continue;
			if (y >= 2 && c[x][y - 2] && c[x][y - 1]) continue;
			break;
		}
#if 0
		fprintf(stderr, "i = %d:\n", i);
		rep(j, 4) { rep(k, 13) fprintf(stderr, "%d ", c[j][k]); fprintf(stderr, "\n"); }
#endif
		c[x][y] = 1;
	   	printf("%d %d\n", x + 1, y + 1);
	}
	return 0;
}

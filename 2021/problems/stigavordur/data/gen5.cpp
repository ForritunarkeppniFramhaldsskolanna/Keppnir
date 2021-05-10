#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

void fischer_yates(int* a, int n)
{
	int i, j, t;
	rep(i, n)
	{
		j = i + rand()%(n - i);
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}

int main(int argc, char** argv)
{
	if (argc == 3) srand(time(NULL));
	else if (argc == 4) srand(atoi(argv[3]));
	else assert(0);
	int i, j, n = atoi(argv[1]), q = atoi(argv[2]);
	printf("%d %d\n", n, q);
	rep(i, n - 1) printf("%d ", rand()%1000000000 + 1);
	printf("%d\n", rand()%1000000000 + 1);
	while (q--)
	{
		int x = rand()%100, y = rand()%n + 1, z = rand()%n + 1;
		if (x < 35) printf("1 %d %d\n", y, rand()%1000000000 + 1);
		else if (q < 3 || x < 85) printf("2 %d %d\n", min(y, z), max(y, z));
		else
		{
			y = rand()%max(1, n - q - 1) + 1;
			z = y + rand()%min(q - 1, n - y);
			int k = (rand()%1000000000)/10 + 1;
			int b[z - y + 1];
			rep(j, z - y + 1) b[j] = j + y;
			fischer_yates(b, z - y + 1);
			rep(i, z - y + 1) q--, printf("1 %d %d\n", b[i], k*(1 + (rand()%(1000000000 - k))/k));
			printf("2 %d %d\n", y, z);
		}
	}
	return 0;
}

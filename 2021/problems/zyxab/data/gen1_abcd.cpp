#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)

void fischer_yates(int* a, int n)
{
	int i, j, t;
	rep(i, n)
	{
		j = i + rand()%(n - i);
		t = a[i], a[i] = a[j], a[j] = t;
	}
}

int main(int argc, char** argv)
{ // Generates |n| random strings, half of which are guaranteed to be uniquly lettered.
	if (argc == 2) srand(time(NULL));
	else if (argc == 3) srand(atoi(argv[2]));
	else assert(0);
	int i, j, n = atoi(argv[1]);
	int r[4];
	rep(i, 4) r[i] = 'a' + i;
	printf("%d\n", n);
	while (n--)
	{
		char s[32];
        rep(i,32) s[i] = 0;
		if (n%2 == 0)
		{
			rep(j, 20) s[j] = rand()%4 + 'a';
			s[j] = '\0';
		}
		else
		{
			fischer_yates(r, 4);
			rep(j, 20) s[j] = r[j];
		}
		printf("%s\n", s);
	}
	return 0;
}

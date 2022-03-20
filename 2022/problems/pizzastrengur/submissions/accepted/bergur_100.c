#include <stdio.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }
int get_int()
{
	int r = 0, c = getchar(), s = 1;
	while (c != '-' && c < '0' || c > '9') c = getchar();
	while (c == '-') s *= -1, c = getchar();
	while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
	return s*r;
}

int query(char *s)
{
	printf("%s\n", s);
	fflush(stdout);
	return get_int();
}

void shuffle(char *a, int m, int n)
{
	int i, j, s;
	rep(i, m)
	{
		j = i + rand()%(n - i);
		s = a[j]; a[j] = a[i]; a[i] = s;
	}
}

int main()
{
	srand(101);
	int i, j, n = get_int(), k = 0;
	char s[n + 1], a[4] = {'P', 'I', 'Z', 'A'};
	rep(i, n + 1) s[i] = '\0';
	while (1)
	{
		shuffle(a, 4, 4);
		rep(i, 3)
		{
			s[k] = a[i];
			j = query(s);
			if (j != 0) break;
		}
		if (j == 2) break;
		s[k++] = a[i];
		if (k == n) { query(s); break; }
	}
	
	return 0;
}

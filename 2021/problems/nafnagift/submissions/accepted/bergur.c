#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 1000
int max(int a, int b) { return a < b ? b : a; }
int get_string(char*, char);

char s[MAXN], t[MAXN], r[MAXN];
int d[MAXN][MAXN], e[MAXN][MAXN], c = 0;
int foo(int x, int y)
{
	if (s[x] == '\0' || t[y] == '\0') return 0;
	if (d[x][y] != -1) return d[x][y];
	if (s[x] == t[y]) d[x][y] = foo(x + 1, y + 1) + 1;
	else d[x][y] = max(foo(x + 1, y), foo(x, y + 1));
	return d[x][y];
}

void goo(int x, int y)
{
	if (s[x] == '\0' || t[y] == '\0') r[c] = '\0';
	else if (s[x] == t[y])
	{
		r[c++] = s[x];
		goo(x + 1, y + 1);
	}
	else if (foo(x + 1, y) < foo(x, y + 1)) goo(x, y + 1);
	else goo(x + 1, y);
}


int main()
{
	int i, j, k, l, p = 0, n = get_string(s, 10), m = get_string(t, 10);
	rep(i, n + 1) rep(j, m + 1) d[i][j] = -1;
	goo(0, 0);
	l = foo(0, 0);
	//printf(">> LCS er '%s'\n", r);
	//printf("%d\n", n + m - l));
	for (i = 0, j = 0, k = 0; k < l; k++)
	{
		while (s[i] != r[k]) printf("%c", s[i++]), p++;
		while (t[j] != r[k]) printf("%c", t[j++]), p++;
		printf("%c", r[k]), i++, j++, p++;
	}
	while (i < n) printf("%c", s[i++]), p++;
	while (j < m) printf("%c", t[j++]), p++;
	printf("\n");
	assert(p == n + m - l);
	return 0;
}

int get_string(char* b, char t)
{
	int i = 0;
	b[i++] = getchar();
	while (b[i - 1] != t) b[i++] = getchar();
	b[i - 1] = '\0';
	return i - 1;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_string(char* b, char t);
int get_int();
char s[100000][21];
typedef struct { int x, y; } par;

int cmp(const void* p1, const void* p2)
{
	return strcmp(s[((par*)p1)->x], s[((par*)p2)->x]);
}

int main()
{ 
	int i, j, n = get_int();
	par a[n];
	rep(i, n)
	{
		a[i].x = i;
		get_string(s[i], ' ');
		a[i].y = get_int();
	}
	qsort(a, n, sizeof(a[0]), cmp);
	int r, mx = 0, mxi = 0;
	i = 0;
	while (i < n)
	{
		j = i, r = 0;
		while (j < n && strcmp(s[a[i].x], s[a[j].x]) == 0) r += a[j++].y;
		if (r > mx) mx = r, mxi = a[i].x;
		i = j;
	}
	printf("%s\n", s[mxi]);
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

int get_int()
{
	int ret = 0;
	char c = getchar();
	int sgn;

	while (1)
	{
		if (c == EOF) return EOF;
		if (c >= '0' && c <= '9') { sgn = 1; break; }
		if (c == '-')
		{
			c = getchar();
			if (c < '0' || c > '9') continue;
			sgn = -1;
			break;
		}
		c = getchar();
	}

	while (1)
	{
		ret = ret*10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') return sgn*ret;
	}
}

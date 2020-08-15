#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_string(char* b, char t);
int get_int();
int main()
{ 
	int i, j, n = get_int();
	int a[n];
	char s[n][21];
	rep(i, n)
	{
		get_string(s[i], ' ');
		a[i] = get_int();
	}
	int r, mx = 0, mxi = 0;
	rep(i, n)
	{
		r = 0;
		rep(j, n) if (strcmp(s[i], s[j]) == 0) r += a[j];
		if (r > mx) mx = r, mxi = i;
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

#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
int get_string(char* b, char t);

int main()
{ 
	int i, j, n = get_int(), m = get_int();
	char s[n], t[n];
	rep(i, n) s[i] = '?';
	rep(i, m)
	{
		int k = get_int() - 1, l = get_string(t, 10);
		rep(j, l) if (s[k + j] != '?' && s[k + j] != t[j]) break; else s[k + j] = t[j];
		if (j < l)
		{
			printf("Villa\n");
			return 0;
		}
	}
	rep(i, n) putchar(s[i]); putchar(10);
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

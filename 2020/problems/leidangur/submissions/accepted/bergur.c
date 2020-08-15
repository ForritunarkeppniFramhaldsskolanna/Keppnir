#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
int get_string(char*, char);
int foo(char a, char b) { return a - 'a' + 'A' == 'b'; }
int goo(char a)
{
	switch (a)
	{
		case 'p': return 0;
		case 'g': return 1;
		case 'o': return 2;
	}
}
int main()
{
	char s[1000001];
	int i, n = get_string(s, 10);
	int q[n], qe = 0;
	rep(i, n)
	{
		if (s[i] == '.') continue;
		if (s[i] >= 'a' && s[i] <= 'z') q[qe++] = s[i];
		else
		{
			while (qe > 0 && q[qe - 1] - 'a' + 'A' != s[i]) qe--;
			if (qe == 0)
			{
				printf("Neibb\n");
				return 0;
			}
			qe--;
		}
	}
	int r[3] = {0, 0, 0};
	while (qe > 0)  r[goo(q[--qe])]++;
	printf("%d\n%d\n%d\n", r[0], r[1], r[2]);
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
	int sgn = 1, ret = 0;
	char c  = getchar();
	while (1)
	{
		if (c == EOF) return EOF;
		if (c >= '0' && c <= '9') break;
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

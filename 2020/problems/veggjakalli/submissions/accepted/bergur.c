#include <stdio.h>
int get_string(char*, char);
int get_int();
int foo(char a) { return a == '#' ? 1 : 0; }
int main()
{ 
	int i, n = get_int(), m = get_int(), mn, t = 0;
	char s[n + 1];
	get_string(s, 10);
	for (i = 1; i < m + 1; i++) t += foo(s[i]);
	mn = (s[m + 1] == '#') ? t : 1000000000;
	for (i = 1 + m; i < n - 1; i++) if (mn > (t = t - foo(s[i - m]) + foo(s[i]))) mn = (s[i + 1] == '#' && s[i - m] == '#') ? t : mn;
	if (mn < 100000000) printf("%d\n", mn);
	else printf("Neibb\n");
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

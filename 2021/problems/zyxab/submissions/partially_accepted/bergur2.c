#include <stdio.h>
#include <string.h>
#define rep(E, F) for (E = 0; E < (F); E++)
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

int unique(char* s)
{
	int c[26], i;
	rep(i, 26) c[i] = 0;
	while (*s != '\0') c[*s++ - 'a']++;
	rep(i, 26) if (c[i] > 1) return 0;
	return 1;
}

int main()
{
	int i, n = get_int(), r = -1;
	char s[n][32];
	rep(i, n) get_string(s[i], 10);
	rep(i, n) if (strlen(s[i]) >= 4 && unique(s[i]) && (r == -1 || strlen(s[i]) < strlen(s[r]) || (strlen(s[i]) == strlen(s[r]) && strcmp(s[r], s[i]) < 0))) r = i;
	if (r == -1) printf("Neibb\n");
	else printf("%s\n", s[r]);
}

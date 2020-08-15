#include <stdio.h>
typedef long long ll;
#define rep(E, F) for (E = 0; E < (F); E++)
int get_string(char*, char);
int get_int();

int main()
{
	ll i, n = get_int(), r = 0, l = 1000000;
	char s[n][32];
	ll a[n];
	rep(i, n) { get_string(s[i], ' '); a[i] = get_int(); }
	int mxi = 0;
	rep(i, n) if (a[mxi] < a[i]) mxi = i;
	printf("%s\n", s[mxi]);
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

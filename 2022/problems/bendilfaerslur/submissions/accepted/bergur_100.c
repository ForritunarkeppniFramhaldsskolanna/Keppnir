#include <stdio.h>
#include <string.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int get_string(char* b, char t)
{
	int i = 0;
	b[i++] = getchar();
	while (b[i - 1] != t) b[i++] = getchar();
	b[i - 1] = '\0';
	return i - 1;
}

int split(char *s, char *t, char **a)
{
	int i, n = 0, m[128];
	char *p;
	rep(i, 128) m[i] = 0;
	if (t) while (*t) m[*t++] = 1;
	else m['\n'] = 1, m['\t'] = 1, m['\r'] = 1, m[' '] = 1;
	if (!m[*s]) a[n++] = s;
	for (p = s; *p; p++) if (m[*p]) a[n++] = p + 1;
	for (p = s; *p; p++) if (m[*p]) *p = '\0';
	return n;
}

char val(int x) { return x + (x <= 9 ? '0' : 'a' - 10); }
int hex(char *s)
{
	int r = 0;
	while (*s) r = r*16 + *s - (*s <= '9' ? '0' : 'a' - 10), s++;
	return r;
}

int main()
{
	char s[1000], *t[100];
	int i, j, n = get_string(s, 10), m, a[100];
	rep(i, n) if (s[i] == ':') break;
	m = split(s, ":.", t);
	if (i < n)
	{ //v6
		rep(i, 8) a[i] = 0;
		for (i = 0; i < 8 && strlen(t[i]) != 0; i++) a[i] = hex(t[i]);
		if (i < 8) for (i = m - 1; i >= 0 && strlen(t[i]) != 0; i--) a[8 - (m  - i)] = hex(t[i]);
		per(i, 8) rep(j, 4) printf("%c.", val((a[i] >> (4*j))&15));
		printf("ip6.arpa.\n");
	}
	else
	{ //v4
		per(i, 4) printf("%s.", t[i]);
		printf("in-addr.arpa.\n");
	}
	return 0;
}

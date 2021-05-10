#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int get_string(char* b)
{
	int i = 0, r;
	b[i++] = getchar();
	while (b[i - 1] != ' ' && b[i - 1] != 10) b[i++] = getchar();
	r = b[i - 1] == ' ';
	b[i - 1] = '\0';
	return r;
}

int main()
{
	char s[30], t[100001];
	int i, a[26];
	get_string(s);
	rep(i, 26) a[i] = 0;
	for (i = 0; s[i] != '\0'; i++) a[s[i] - 'a'] = 1;
	int r = get_string(t);
	while (1)
	{
		for (i = 0; t[i] != '\0'; i++) if (a[t[i] - 'a'] == 1) break;
		if (t[i] != '\0') for (i = 0; t[i] != '\0'; i++) printf("*");
		else for (i = 0; t[i] != '\0'; i++) printf("%c", t[i]);
		printf(" ");
		if (!r) break;
		r = get_string(t);
	}
	printf("\n");
	return 0;
}

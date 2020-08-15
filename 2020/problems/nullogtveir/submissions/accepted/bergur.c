#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_string(char* b, char t)
{
	int i = 0;
	b[i++] = getchar();
	while (b[i - 1] != t) b[i++] = getchar();
	b[i - 1] = '\0';
	return i - 1;
}

int main()
{
	char s[100];
	int i, n = get_string(s, 10);
	long long r = 0;
	rep(i, n)
	{
		if (i == n - 1) r += 1 + (s[i] >= '2' ? 1 : 0);
		else if (s[i] > '2')
		{
			r += (1LL << (n - i));
			break;
		}
		else if (s[i] == '1') 
		{
			r += (1LL << (n - i - 1));
			break;
		}
		else if (s[i] != '0') r += (1LL << (n - i - 1));
	}
	printf("%lld\n", r);
}

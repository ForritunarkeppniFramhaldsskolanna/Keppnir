#include <cstdio>
using namespace std;

void line(int n, int i, char c)
{
    if (n > 0) printf(" ");
	printf("%c", c);

	if (i > 0)
	{
		if (i > 0) printf(" ");
		printf("%c", c);
	}

	printf("\n");
}

int main()
{
	int n;
	char c;
	scanf("%d %c\n", &n, &c);

	for (int i = 0; i < n; i++) line(n - i - 1, 2 * i - 1, c);
	for (int i = n - 2; i >= 0; i--) line(n - i - 1, 2 * i - 1, c);

	return 0;
}

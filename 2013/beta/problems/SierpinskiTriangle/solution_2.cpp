#include <cstdio>
using namespace std;

bool isOddBinomial(int n, int k)
{
	for (int i = 0; i < 31; i++)
	{
		if ((k & (1 << i)) > (n & (1 << i)))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%c", isOddBinomial(i, j) ? '#' : '.');
		}

		printf("\n");
	}
	return 0;
}
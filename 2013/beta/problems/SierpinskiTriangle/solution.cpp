#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d\n", &n);
	n--;
	int* arr[2];
	for (int i = 0; i < 2; i++)
		arr[i] = new int[n];

	arr[0][0] = 1;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%c", arr[i & 1][j] % 2 == 0 ? '.' : '#');
		}

		printf("\n");

		for (int j = 0; j <= i + 1; j++)
		{
			arr[~i & 1][j] = j == 0 || j == i + 1 ? 1 : (arr[i & 1][j - 1] + arr[i & 1][j]) % 2;
		}
	}

	return 0;
}
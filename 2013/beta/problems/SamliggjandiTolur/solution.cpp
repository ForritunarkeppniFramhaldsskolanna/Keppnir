#include <cstdio>
using namespace std;

int main()
{
	int mx = 10000 + 100;
	int* cnt[10];

	for (int i = 0; i < 10; i++)
	{
		cnt[i] = new int[mx];
		cnt[i][0] = 0;
	}

	for (int i = 1; i < mx; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cnt[j][i] = cnt[j][i-1];
		}

		int t = i;
		while (t)
		{
			cnt[t % 10][i]++;
			t /= 10;
		}
	}

	int ts;
	scanf("%d\n", &ts);
	for (int t = 0; t < ts; t++)
	{
		int n;
		scanf("%d\n", &n);
		for (int i = 0; i < 10; i++)
		{
			if (i != 0) printf(" ");
			printf("%d", cnt[i][n]);
		}

		printf("\n");
	}

	return 0;
}
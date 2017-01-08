#include <cstdio>
using namespace std;

int main()
{
	unsigned int N, L, U;
	while (scanf("%u %u %u\n", &N, &L, &U) != EOF)
	{
		unsigned int M = L;
		for (int i = 31; i >= 0; i--)
		{
			if (N & (1u << i))
			{
				unsigned int nxtM = (M & ~(1u << i)) | ((1u << i) - 1);
				if (L <= nxtM && nxtM <= U) M = nxtM;
			}
			else
			{
				unsigned int nxtM = (M | (1u << i)) & ~((1u << i) - 1);
				if (L <= nxtM && nxtM <= U) M = nxtM;
			}
		}

		printf("%u\n", M);
	}

	return 0;
}
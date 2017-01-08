#include <cstdio>
using namespace std;

int main()
{
	unsigned int N, L, U;
	while (scanf("%u %u %u\n", &N, &L, &U) != EOF)
	{
		unsigned int M = L,
					 mx = N | M,
					 cur;

		for (unsigned int i = U; i > L; i--)
		{
			cur = N | i;
			if (cur >= mx)
			{
				mx = cur;
				M = i;
			}
		}

		if ((N | L) >= mx)
		{
			M = L;
		}

		printf("%u\n", M);
	}

	return 0;
}
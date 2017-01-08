#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T x) { return x.size(); }

// assert or gtfo

int main()
{
	int ts;
	scanf("%d\n", &ts);

	unsigned int N, L, U;
	for (int t = 0; t < ts; t++)
	{
		scanf("%u %u %u\n", &N, &L, &U);

		unsigned int M = U;
		for (int i = 31; i >= 0; i--)
		{
			if (N & (1u << i))
			{
				if (M & (1u << i))
				{
					unsigned int nxtM = (M & ~(1u << i)) | ((1u << i) - 1);
					if (L <= nxtM) M = nxtM;
				}
			}
			else
			{
				if (~M & (1u << i))
				{
					unsigned int nxtM = (M | (1u << i)) & ~((1u << i) - 1);
					if (nxtM <= U) M = nxtM;
				}
			}
		}

		printf("%u\n", M);
	}

	return 0;
}
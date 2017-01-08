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

	for (int t = 0; t < ts; t++)
	{
		int n;
		scanf("%d\n", &n);
		int* cnt = new int[10];
		memset(cnt, 0, 10 << 2);

		for (int i = 1; i <= n; i++)
		{
			int tmp = i;
			while (tmp)
			{
				cnt[tmp % 10]++;
				tmp /= 10;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if (i != 0) printf(" ");
			printf("%d", cnt[i]);
		}

		printf("\n");
	}

	return 0;
}
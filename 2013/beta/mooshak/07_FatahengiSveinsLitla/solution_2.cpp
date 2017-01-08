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
		int* arr = new int[n];
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}

		do
		{
			bool any = false;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] == i)
				{
					any = true;
					break;
				}
			}

			if (!any)
			{
				cnt++;
			}
		} while (next_permutation(arr, arr + n));

		printf("%d\n", cnt);
	}

	return 0;
}
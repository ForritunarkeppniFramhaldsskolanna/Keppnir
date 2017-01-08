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

bool is_prime(int n)
{
	if (n < 2) return false;
	if (n < 4) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	if (n < 25) return true;

	int st = static_cast<int>(sqrt(static_cast<double>(n)));
	for (int i = 5; i <= st; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}

	return true;
}

int main()
{
	int cnt = 1000;
	int* arr = new int[cnt];

	for (int i = 1, j = 0; j < cnt; i++)
	{
		if (is_prime(i))
		{
			arr[j++] = i;
		}
	}

	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int n;
		scanf("%d\n", &n);
		printf("%d\n", arr[n - 1]);
	}

	return 0;
}
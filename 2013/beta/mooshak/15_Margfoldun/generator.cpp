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
	srand(time(NULL));
	int ts = 100;
	printf("%d\n", ts);

	for (int t = 0; t < ts; t++)
	{
		int a = rand() % 100,
			b = rand() % 100,
			c;

		if (rand() % 2 == 0)
		{
			c = a * b;
		}
		else
		{
			c = rand() % 10000;
		}

		printf("%d %d %d\n", a, b, c);
	}

	return 0;
}
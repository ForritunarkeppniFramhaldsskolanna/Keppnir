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

bool is_leap_year(int Y)
{
	if (Y % 4 == 0)
	{
		if (Y % 100 == 0)
		{
			if (Y % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

int days_in_month(int M, int Y)
{
	if (M == 1) return 31;
	if (M == 2) return is_leap_year(Y) ? 29 : 28;
	if (M == 3) return 31;
	if (M == 4) return 30;
	if (M == 5) return 31;
	if (M == 6) return 30;
	if (M == 7) return 31;
	if (M == 8) return 31;
	if (M == 9) return 30;
	if (M == 10) return 31;
	if (M == 11) return 30;
	if (M == 12) return 31;
	assert(false);
}

int main()
{
	// assert(!is_leap_year(1800));
	// assert(!is_leap_year(1900));
	// assert(is_leap_year(2000));
	// assert(is_leap_year(2012));
	// assert(!is_leap_year(2013));

	int ts;
	scanf("%d\n", &ts);
	for (int t = 0; t < ts; t++)
	{
		int Y;
		scanf("%d\n", &Y);

		int wd = 0,
			d = 15,
			m = 3,
			y = 2013;

		wd = ((wd - (d - 1)) % 7 + 7) % 7;
		d -= (d - 1);
		while (m > 1)
		{
			wd = ((wd - days_in_month(m, y)) % 7 + 7) % 7;
			m--;
		}

		while (y > Y)
		{
			for (int i = 12; i >= 1; i--)
			{
				wd = ((wd - days_in_month(i, y-1)) % 7 + 7) % 7;
			}

			y--;
		}

		while (y < Y)
		{
			for (int i = 1; i <= 12; i++)
			{
				wd = ((wd + days_in_month(i, y)) % 7 + 7) % 7;
			}

			y++;
		}

		int count = 0;

		for (int i = 1; i <= 12; i++)
		{
			if ((wd + 13 - 1) % 7 == 0)
			{
				count++;
			}

			wd = (wd + days_in_month(i, y)) % 7;
		}

		printf("%d\n", count);
	}

	return 0;
}
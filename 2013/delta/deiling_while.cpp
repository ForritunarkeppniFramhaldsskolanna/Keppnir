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
	while (true)
	{
		int x, y;
		printf("Fyrri heiltala: ");
		scanf("%d", &x);
		printf("Seinni heiltala: ");
		scanf("%d", &y);
		printf("%d gengur %d sinnum upp í %d\n", y, x / y, x);

		if (x % y == 0)
		{
			printf("Enginn afgangur\n");
		}
		else
		{
			printf("Afgangur er %d\n", x % y);
		}

		printf("Viltu endurtaka vinnslu (j eða n)? ");
		char c;
		scanf("\n");
		scanf("%c", &c);

		if (c == 'n') break;
	}
	return 0;
}
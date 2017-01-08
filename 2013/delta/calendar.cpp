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
	printf("Dagar í mánuðinum: ");
	int n;
	scanf("%d", &n);
	printf("Fyrsti dagur mánaðarins: ");
	int first;
	scanf("%d", &first);

	printf("\n");

	printf("Sun Mán Þri Mið Fim Fös Lau\n");

	for (int cur = 2 - first, day = 0; cur <= n; cur++, day = (day + 1) % 7)
	{
		if (day	== 0 && cur > 1) printf("\n");
		if (cur >= 1) printf("%3d", cur);
		else printf("   ");
		printf(" ");
	}

	printf("\n");

	return 0;
}
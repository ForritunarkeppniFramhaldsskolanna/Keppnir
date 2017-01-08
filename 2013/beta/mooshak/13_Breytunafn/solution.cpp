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
	scanf("%d", &ts);

	string tmp;
	getline(cin, tmp);

	for (int t = 0; t < ts; t++)
	{
		string line;
		getline(cin, line);

		bool valid = true;

		valid = valid && size(line) > 0;

		for (int i = 0, cnt = size(line); valid && i < cnt; i++)
		{
			char c = line[i];
			valid = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
		}

		valid = valid && !(line[0] >= '0' && line[0] <= '9');

		if (valid)
		{
			printf("Valid\n");
		}
		else
		{
			printf("Invalid\n");
		}
	}

	return 0;
}
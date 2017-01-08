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
	map<char, int> cntz;

	string line;
	getline(cin, line);

	int total = 0;

	for (int i = 0, cnt = size(line); i < cnt; i++)
	{
		if (line[i] >= 'a' && line[i] <= 'z')
		{
			cntz[line[i]]++;
			total++;
		}
		else if (line[i] >= 'A' && line[i] <= 'Z')
		{
			cntz[line[i] - 'A' + 'a']++;
			total++;
		}
	}

	vector<pair<int, char> > res;
	for (map<char, int>::const_iterator it = cntz.begin(); it != cntz.end(); it++)
	{
		res.push_back(pair<int, char>(-it->second, it->first));
	}

	sort(all(res));

	for (int i = 0, cnt = size(res); i < cnt; i++)
	{
		cout << res[i].second << " " << 100 * static_cast<double>(-res[i].first) / total << "%" << endl;
	}

	return 0;
}
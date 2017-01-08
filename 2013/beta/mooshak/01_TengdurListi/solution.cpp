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
		string line;
		getline(cin, line);

		vector<int> nums;

		int buffer = 0;
		bool in_brackets = false;
		for (int i = 0, cnt = size(line); i < cnt; i++)
		{
			if (line[i] == ']')
			{
				in_brackets = false;
				nums.push_back(buffer);
			}
			else if (line[i] == '[')
			{
				in_brackets = true;
				buffer = 0;
			}
			else if (in_brackets)
			{
				buffer = buffer * 10 + (line[i] - '0');
			}
		}

		reverse(all(nums));

		for (int i = 0, cnt = size(nums); i < cnt; i++)
		{
			printf("[%d]->", nums[i]);
		}

		printf("NULL\n");
	}

	return 0;
}
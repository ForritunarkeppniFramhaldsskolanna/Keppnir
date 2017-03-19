#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
    long long s;
	vector<long long> vals;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		long long v;
		cin >> v;
		vals.push_back(v);
	}
	
	sort(vals.begin(), vals.end());
	int start = 0, end = n-1;
	for (int i = 0; i < n && start < end; i++)
	{
		long long v = vals[start] + vals[end];
		if (v == s)
		{
			cout << vals[start] << " " << vals[end] << endl;
			return 0;
		}
		else if (v > s)
		{
			end--;
		}
		else
		{
			start++;
		}
	}
	cout << "neibb" << endl;
	return 0;
}


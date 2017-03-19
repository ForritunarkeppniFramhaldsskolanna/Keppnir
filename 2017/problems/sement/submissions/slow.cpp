#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, s;
	vector<long long> vals;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		vals.push_back(v);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((long long)vals[i] + vals[j] == s)
			{
				cout << vals[i] << " " <<  vals[j] << endl;
				return 0;
			}
		}
	}
	cout << "neibb" << endl;
	return 0;
}


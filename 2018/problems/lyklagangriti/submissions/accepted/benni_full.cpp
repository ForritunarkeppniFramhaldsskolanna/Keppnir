#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

int main() {
    cin.sync_with_stdio(false);
	char s;
	vector<char> first;
	vector<char> second;
	while(cin >> s) {
		if(s == 'L') {
			char k = first.back();
			first.pop_back();
			second.push_back(k);
		} else if(s == 'R') {
			char  k = second.back();
			second.pop_back();
			first.push_back(k);
		} else if(s == 'B') {
			first.pop_back();
		} else {
			first.push_back(s);
		}
	}
	string h1 = "";
	rep(i,0,first.size()) h1 += first[i];
	for(int i = second.size()-1; i >= 0; i--) h1 += second[i];
	cout << h1 << endl;
    return 0;
}



#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)
const int INF = 2147483647;
const double EPS = 1e-9;
const double pi = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }
template <class T> int size(const T &x) { return x.size(); }

int main(){
    string td, c1, c2, text;
    string line;
    getline(cin, line);
    getline(cin, text);
    stringstream ss(line);
    ss >> td;
    if(td == "t"){
        ss >> c1 >> c2;
        for(int i = 0; i < size(text); ++i){
            if(text[i] == c1[0]){
                cout << c2;
            } else {
                cout << text[i];
            }
        }
    } else {
        ss >> c1 >> text;
        for(int i = 0; i < size(text); ++i){
            if(text[i] != c1[0]){
                cout << text[i];
            }
        }
    }
    cout << endl;
}

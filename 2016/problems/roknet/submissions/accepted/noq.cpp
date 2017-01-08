#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define OSATT 0
#define SATT 1

int parse_bool(string s) {
    if (s == "SATT") {
        return SATT;
    } else if (s == "OSATT") {
        return OSATT;
    } else {
        return SATT;
    }
}

int main() {
    map<string, int> data;
    int n;
    cin >> n;
    rep(i,0,n) {
        string op;
        cin >> op;
        if (op == "INNTAK") {
            string name, val;
            cin >> name >> val;
            assert(data.find(name) == data.end());
            data[name] = parse_bool(val);
        } else if (op == "UTTAK") {
            string name;
            cin >> name;
            assert(data.find(name) != data.end());
            if (data[name] == SATT) {
                cout << name << " " << "SATT" << endl;
            } else if (data[name] == OSATT) {
                cout << name << " " << "OSATT" << endl;
            }
        } else if (op == "EDA") {
            string namea, nameb, outp;
            cin >> namea >> nameb >> outp;
            assert(data.find(namea) != data.end());
            assert(data.find(nameb) != data.end());
            int x = data[namea],
                y = data[nameb],
                z = (x == SATT || y == SATT) ? SATT : (x == OSATT && y == OSATT) ? OSATT : SATT;
            assert(data.find(outp) == data.end());
            data[outp] = z;
        } else if (op == "OG") {
            string namea, nameb, outp;
            cin >> namea >> nameb >> outp;
            assert(data.find(namea) != data.end());
            assert(data.find(nameb) != data.end());
            int x = data[namea],
                y = data[nameb],
                z = (x == SATT && y == SATT) ? SATT : (x == OSATT || y == OSATT) ? OSATT : SATT;
            assert(data.find(outp) == data.end());
            data[outp] = z;
        } else if (op == "EKKI") {
            string name, outp;
            cin >> name >> outp;
            assert(data.find(name) != data.end());
            int x = data[name],
                z = (x == OSATT) ? SATT : (x == SATT) ? OSATT : SATT;
            assert(data.find(outp) == data.end());
            data[outp] = z;
        } else {
            assert(false);
        }
    }

    return 0;
}


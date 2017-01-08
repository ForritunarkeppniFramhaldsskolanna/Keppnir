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

int tat = 0, truth = 0;

int parse_bool(string s) {
    if (s == "SATT") {
        return SATT;
    } else if (s == "OSATT") {
        return OSATT;
    } else {
        return truth & (1<<(tat++)) ? SATT : OSATT;
    }
}

int main() {
    stringstream sinp;
    string tmp;
    while (cin >> tmp) {
        sinp << tmp << " ";
    }
    string inp = sinp.str();
    vector<string> outputs;
    map<string,set<int> > vals;
    // for (truth = 0; truth < (1<<5); truth++) {
    tat = 0;
    outputs.clear();
    stringstream curin(inp);
    map<string, int> data;
    int n;
    curin >> n;
    rep(i,0,n) {
        string op;
        curin >> op;
        if (op == "INNTAK") {
            string name, val;
            curin >> name >> val;
            assert(data.find(name) == data.end());
            data[name] = parse_bool(val);
        } else if (op == "UTTAK") {
            string name;
            curin >> name;
            assert(data.find(name) != data.end());
            outputs.push_back(name);
            vals[name].insert(data[name]);
        } else if (op == "EDA") {
            string namea, nameb, outp;
            curin >> namea >> nameb >> outp;
            assert(data.find(namea) != data.end());
            assert(data.find(nameb) != data.end());
            int x = data[namea],
                y = data[nameb],
                z = (x == SATT || y == SATT) ? SATT : (x == OSATT && y == OSATT) ? OSATT : SATT;
            assert(data.find(outp) == data.end());
            data[outp] = z;
        } else if (op == "OG") {
            string namea, nameb, outp;
            curin >> namea >> nameb >> outp;
            assert(data.find(namea) != data.end());
            assert(data.find(nameb) != data.end());
            int x = data[namea],
                y = data[nameb],
                z = (x == SATT && y == SATT) ? SATT : (x == OSATT || y == OSATT) ? OSATT : SATT;
            assert(data.find(outp) == data.end());
            data[outp] = z;
        } else if (op == "EKKI") {
            string name, outp;
            curin >> name >> outp;
            assert(data.find(name) != data.end());
            int x = data[name],
                z = (x == OSATT) ? SATT : (x == SATT) ? OSATT : SATT;
            assert(data.find(outp) == data.end());
            data[outp] = z;
        } else {
            assert(false);
        }
    }
    // }

    iter(it,outputs) {
        if (size(vals[*it]) > 1) {
            cout << *it << " " << "?" << endl;
        } else {
            int x = *vals[*it].begin();
            if (x == SATT) {
                cout << *it << " " << "SATT" << endl;
            } else if (x == OSATT) {
                cout << *it << " " << "OSATT" << endl;
            }
        }
    }

    return 0;
}


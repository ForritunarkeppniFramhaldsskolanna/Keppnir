#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

template <class T> int size(const T &x) { return x.size(); }

int opposite(int c) {
    return c == 1 ? 2 : 1;
}

int main() {

    int n;
    cin >> n;

    map<string, int> id;
    vector<string> names;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        id[s] = i;
        names.push_back(s);
    }

    int m;
    cin >> m;

    vector<int> *adj = new vector<int>[n];
    vector<pair<int, int> > suspicious(m);
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        int x = id[a],
            y = id[b];

        suspicious[i] = make_pair(x, y);
    }

    bool found = false;
    for (unsigned long long ass = 0; ass < (1ULL << n); ass++) {

        bool ok = true;
        for (int i = 0; i < m; i++) {
            int x = suspicious[i].first,
                y = suspicious[i].second;

            bool x_in_set = ass & (1ULL << x),
                 y_in_set = ass & (1ULL << y);

            if (x_in_set == y_in_set) {
                ok = false;
                break;
            }
        }

        if (ok) {
            found = true;

            bool first = true;
            for (int i = 0; i < n; i++) {
                if (ass & (1ULL << i)) {
                    if (first) first = false;
                    else cout << " ";
                    cout << names[i];
                }
            }

            cout << endl;

            first = true;
            for (int i = 0; i < n; i++) {
                if (~ass & (1ULL << i)) {
                    if (first) first = false;
                    else cout << " ";
                    cout << names[i];
                }
            }

            cout << endl;

            break;
        }
    }

    if (!found) {
        cout << "impossible" << endl;
    }

    delete[] adj;
    return 0;
}


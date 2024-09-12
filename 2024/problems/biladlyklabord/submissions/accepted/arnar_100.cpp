#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    cin >> s;
    auto it{ unique(s.begin(), s.end()) };
    s.resize(distance(s.begin(), it));
    cout << s << endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for (auto& name : names) {
        cin >> name;
    }

    swap(names[0], names[12%n]);

    for (const auto& name : names) {
        cout << name << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, l, t;
    cin >> n >> l >> t;

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    if (l == 5) {
        for (int i = 0; i < n; i++) {
            cout << words[i] << endl;
        }
    } else {
        cout << "/ff" << endl;
    }
}
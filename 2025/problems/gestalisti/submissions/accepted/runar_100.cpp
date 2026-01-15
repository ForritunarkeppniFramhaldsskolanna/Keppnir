#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> guestBook;

    for (int i = 0; i < n; ++i) {
        char operation;
        cin >> operation;

        string name;
        getline(cin, name);

        if (operation == '+') {
            guestBook.insert(name);
        } else if (operation == '-') {
            guestBook.erase(name);
        } else if (operation == '?') {
            cout << (guestBook.find(name) != guestBook.end() ? "Jebb"
                                                             : "Neibb");
            cout << endl;
        }
    }

    return 0;
}

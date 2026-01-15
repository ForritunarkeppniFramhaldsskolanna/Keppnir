#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
    string a, b;
    cin >> a >> b;

    if (a < b) {
        cout << "Dufur passa\n";
    }
    if (a > b) {
        cout << "Dufur passa ekki\n";
    }
    if (a == b) {
        cout << "Dufur passa fullkomlega\n";
    }
    return 0;
}

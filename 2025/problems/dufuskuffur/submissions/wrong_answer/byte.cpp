#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

int main() {
    int8_t a, b;
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

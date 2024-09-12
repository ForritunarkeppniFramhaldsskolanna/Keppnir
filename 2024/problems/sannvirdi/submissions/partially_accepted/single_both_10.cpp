#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n;
    cin >> n;

    string name;
    size_t guess;
    cin >> name >> guess;
   
    size_t q;
    cin >> q;

    size_t value;
    cin >> value;
    if (value < guess) {
        cout << ":(" << endl;
    }
    else {
        cout << name << endl;
    }

    return 0;
}

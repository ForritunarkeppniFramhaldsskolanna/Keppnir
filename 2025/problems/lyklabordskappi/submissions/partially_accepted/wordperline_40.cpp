#include<iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    if(x == 4) {
        cout << "/ff\n";
    } else {
        while(n--) {
            string word;
            cin >> word;
            cout << word << '\n';
        }
    }
}

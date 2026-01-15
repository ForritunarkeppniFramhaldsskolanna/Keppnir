#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
    int n, m;
    string box;
    cin >> n >> box >> m;
    cout << (n == m ? "Goggi svangur!" : (n < m ? "<" : ">")) << "\n";
    return 0;
}

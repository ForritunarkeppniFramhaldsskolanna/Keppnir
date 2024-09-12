#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << "?";
    for (int i = 0; i < n; i++) {
        cout << " " << i;
    }
    cout << endl;

    int response = 0;
    cin >> response;
    cout << "! col" << (response % n) + 1 << endl;

    return 0;
}

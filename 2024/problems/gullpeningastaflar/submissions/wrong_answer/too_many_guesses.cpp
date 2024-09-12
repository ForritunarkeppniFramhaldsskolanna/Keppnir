#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int response = 0;
    for (int j = 0; j < 3*n; j++) {
        cout << "?";
        for (int i = 0; i < n; i++) {
            cout << " " << i;
        }
        cout << endl;
        cin >> response;
    }

    cout << "! " << (response % n) + 1 << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "?";
        for (int j = 0; j < n; j++) {
            cout << " " << (i == j ? 1 : 0);
        }
        cout << endl;

        int response = 0;
        cin >> response;
        if (response != n) {
            cout << "! " << i+1 << endl;
            break;
        }
    }

    return 0;
}

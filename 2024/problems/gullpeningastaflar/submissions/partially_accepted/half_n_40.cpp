#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int answer = 0;   
    for (int i = 0; i < n / 2; i++) {
        cout << "?";
        for (int j = 0; j < n; j++) {
            cout << " " << (i == j / 2 ? 1 : 0);
        }
        cout << endl;

        int response = 0;
        cin >> response;
        if (response % n != 0) {
            cout << "?";
            for (int j = 0; j < n; j++) {
                cout << " " << (i == j / 2 && j % 2 == 0 ? 1 : 0);
            }
            cout << endl;
            cin >> response;
            if (response % n != 0) {
                answer = 2 * i + 1;
            }
            else {
                answer = 2 * i + 2;
            }
        }
    }
    cout << "! " << answer << endl;

    return 0;
}

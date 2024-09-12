#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int answer = 0;    
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (lo + 1 == hi) {
            answer = lo + 1;
            break;
        }
        cout << "?";
        for (int j = 0; j < n; j++) {
            cout << " " << (j < mid ? 1 : 0);
        }
        cout << endl;
        int response;
        cin >> response;
        if (response % n != 0) {
            hi = mid;
        }
        else {
            lo = mid;

        }
    }
    cout << "! " << answer << endl;

    return 0;
}

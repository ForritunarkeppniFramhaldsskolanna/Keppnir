#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    if (a*a + b*b == c*c)
    {
        cout << a*b/2 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}

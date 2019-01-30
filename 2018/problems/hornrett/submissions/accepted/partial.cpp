#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a*a+b*b==c*c ? a*b/2 : -1) << endl;
    return 0;
}

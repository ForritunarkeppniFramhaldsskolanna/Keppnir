#include <bits/stdc++.h>

using namespace std;

int main()
{
    int trump, un;
    cin >> trump >> un;
    if (trump > un)
    {
        cout << "MAGA!" << endl;
    }
    else if (un > trump)
    {
        cout << "FAKE NEWS!" << endl;
    }
    else
    {
        cout << "WORLD WAR 3!" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string input;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        input[0] = input[0] - 32;
        cout << input << endl;
    }

}
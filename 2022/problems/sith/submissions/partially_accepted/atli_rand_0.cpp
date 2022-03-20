#include<bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));
    int t = rand() % 3;
    if(t == 0) cout << "VEIT EKKI\n";
    else if(t == 1) cout << "JEDI\n";
    else cout << "SITH\n";
}

#include<bits/stdc++.h>
using namespace std;

int main() {
    int k1, k2;
    char pt;
    cin >> k1 >> pt >> k2;
    k1 *= 10; k1 += k2;
    if(k1 <= 2) cout << "Logn\n";
    else if(k1 <= 14) cout << "Andvari\n";
    else if(k1 <= 33) cout << "Kul\n";
    else if(k1 <= 54) cout << "Gola\n";
    else if(k1 <= 79) cout << "Stinningsgola\n";
    else if(k1 <= 107) cout << "Kaldi\n";
    else if(k1 <= 138) cout << "Stinningskaldi\n";
    else if(k1 <= 171) cout << "Allhvass vindur\n";
    else if(k1 <= 207) cout << "Hvassvidri\n";
    else if(k1 <= 244) cout << "Stormur\n";
    else if(k1 <= 284) cout << "Rok\n";
    else if(k1 <= 326) cout << "Ofsavedur\n";
    else cout << "Farvidri\n";
}

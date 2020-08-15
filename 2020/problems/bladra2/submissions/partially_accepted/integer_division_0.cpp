#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int v,a,t;
    cin >> v >> a>> t;
    
    double out = (v*t) + ((a*(t*t))/2);
    
    cout << setprecision(10) << fixed << out << endl;
    
    return 0;
}

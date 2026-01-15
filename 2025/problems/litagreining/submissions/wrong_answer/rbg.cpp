#include<iostream>
#include<cassert>
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> b >> g;
    if(r > g && r > b) cout << "raudur\n";
    else if(g > r && g > b) cout << "graenn\n";
    else if(b > r && b > g) cout << "blar\n";
    else if(r == g && g > b) cout << "gulur\n";
    else if(r == b && b > g) cout << "fjolubleikur\n";
    else if(g == b && b > r) cout << "blagraenn\n";
    else if(r == b && b == g && g == 0) cout << "svartur\n";
    else if(r == b && b == g && g == 255) cout << "hvitur\n";
    else if(r == g && g == b) cout << "grar\n";
    else assert(false);
}

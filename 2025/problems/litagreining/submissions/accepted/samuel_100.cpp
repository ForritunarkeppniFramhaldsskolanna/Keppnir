#include <iostream>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    if (r > g && r > b) {
        cout << "raudur" << endl;
    } else if (g > r && g > b) {
        cout << "graenn" << endl;
    } else if (b > r && b > g) {
        cout << "blar" << endl;
    } else if ( r == g && r == b ) {
        if (r == 0) cout << "svartur" << endl;
        else if (r == 255) cout << "hvitur" << endl;
        else cout << "grar" << endl;
    } else if (r == g) {
        cout << "gulur" << endl;
    } else if (r == b) {
        cout << "fjolubleikur" << endl;
    } else if (g == b) {
        cout << "blagraenn" << endl;
    }

    return 0;
}

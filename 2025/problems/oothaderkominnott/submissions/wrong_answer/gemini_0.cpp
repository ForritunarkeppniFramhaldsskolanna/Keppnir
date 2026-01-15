#include <iostream>

using namespace std;

int main() {
    int i;
    cin >> i;

    if (i == 1) {
        int l;
        cin >> l;
        int h = 3;
        int total_blocks = 2 * (l * h) + 2 * (l * h) - 4 * h + l * l - (l-2) * (l-2) ;
        cout << total_blocks << endl;
    } else if (i == 2) {
        int w, l;
        cin >> w >> l;
        int h = 3;
        int total_blocks = 2 * (w * h) + 2 * (l * h) - 4 * h+ w * l - (w-2) * (l-2);
        cout << total_blocks << endl;
    } else if (i == 3) {
        int w, l, h;
        cin >> w >> l >> h;
        int total_blocks = 2 * (w * h) + 2 * (l * h) - 4 * h + w * l - (w-2) * (l-2);
        cout << total_blocks << endl;
    }

    return 0;
}

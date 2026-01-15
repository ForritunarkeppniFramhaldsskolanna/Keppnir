#include <iostream>
#include <string>

using namespace std;

int main() {
  int R, G, B;
  cin >> R >> G >> B;

  if (R == 0 && G == 0 && B == 0) {
    cout << "svartur" << endl;
  } else if (R == 255 && G == 255 && B == 255) {
    cout << "hvitur" << endl;
  } else if (R == G && G == B) {
    cout << "grar" << endl;
  } else if (R > G && R > B) {
    cout << "raudur" << endl;
  } else if (G > R && G > B) {
    cout << "graenn" << endl;
  } else if (B > R && B > G) {
    cout << "blar" << endl;
  } else if (R == G && B < R) {
    cout << "gulur" << endl;
  } else if (R == B && G < R) {
    cout << "fjolubleikur" << endl;
  } else if (G == B && R < G) {
    cout << "blagraenn" << endl;
  } else {
    cout << "othekkt" << endl;
  }

  return 0;
}

#include <iostream>

int main() {
    int windows, drawn_curtains;
    std::cin >> windows >> drawn_curtains;
    std::cout << (windows - drawn_curtains) << std::endl;
    return 0;
}

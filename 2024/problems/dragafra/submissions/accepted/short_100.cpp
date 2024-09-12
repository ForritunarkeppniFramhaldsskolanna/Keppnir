#include <iostream>

int main() {
    int16_t windows, drawn_curtains;
    std::cin >> windows >> drawn_curtains;
    std::cout << (windows - drawn_curtains) << std::endl;
    return 0;
}

#include <iostream>

int main() {
    int n, m;
    char question_mark;
    std::cin >> n >> question_mark >> m;

    if (n > m) {
        std::cout << ">" << std::endl;
    } else if (n < m) {
        std::cout << "<" << std::endl;
    } else {
        std::cout << "Goggi svangur!" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    if (input == "a") {
        std::cout << "b" << std::endl;
    } else {
        std::cout << "a" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>

int main() {
    std::string filename;
    std::cin >> filename;

    size_t last_dot_pos = filename.find_last_of('.');
    if (last_dot_pos != std::string::npos) {
        std::cout << filename.substr(last_dot_pos) << std::endl;
    }

    return 0;
}

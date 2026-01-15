#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;
    std::unordered_set<std::string> guestList;
    for (int i = 0; i < N; ++i) {
        char command;
        std::string name;
        std::cin >> command >> name;
        if (command == '+') {
            guestList.insert(name);
        } else if (command == '-') {
            guestList.erase(name);
        } else if (command == '?') {
            if (guestList.count(name)) {
                std::cout << "Jebb" << std::endl;
            } else {
                std::cout << "Neibb" << std::endl;
            }
        }
    }
    return 0;
}

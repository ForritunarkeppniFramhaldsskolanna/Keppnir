#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct contestant_t {
    size_t guess;
    std::string name;
};

int main() {
    size_t n;
    cin >> n;

    vector<contestant_t> contestants(n);
    for (auto& [guess, name] : contestants) {
        cin >> name >> guess;
    }
   
    size_t q;
    cin >> q;

    size_t value;
    cin >> value;
    contestant_t best{ 0, ":(" };
    for (auto& [guess, name] : contestants) {
        if (guess <= value && guess >= best.guess) {
            best = {guess, name};
        }
    }

    cout << best.name << endl;

    return 0;
}

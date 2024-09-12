#include <algorithm>
#include <iostream>
#include <vector>

struct meme_t {
    int controversy;
    int coolness;
    std::string filename;

    constexpr int get_likes() const {
        return controversy * coolness;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<meme_t> memes(n);
    for (auto& [controversy, coolness, filename] : memes) {
        std::cin >> filename >> controversy >> coolness;
        controversy++;
    }

    auto best = std::max_element(
        memes.begin(),
        memes.end(),
        [](auto& a, auto& b) {
            return a.get_likes() == b.get_likes()
                ? a.filename > b.filename
                : a.get_likes() < b.get_likes();
        }
    );
    
    std::cout << best->filename << std::endl;

    return 0;
}

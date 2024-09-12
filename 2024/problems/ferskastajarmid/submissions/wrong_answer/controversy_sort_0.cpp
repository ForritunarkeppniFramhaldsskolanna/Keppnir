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
    }

    auto best = std::max_element(
        memes.begin(),
        memes.end(),
        [](auto& a, auto& b) {
            return a.controversy < b.controversy;
        }
    );
    
    std::cout << best->filename << std::endl;

    return 0;
}

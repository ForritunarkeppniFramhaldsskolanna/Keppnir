#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct contestant_t {
    size_t guess;
    std::string name;
};

struct idea_t {
    size_t index;
    size_t value;
    size_t winner;
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
    vector<idea_t> ideas(q);

    for (size_t i = 0; i < q; i++) {
        ideas[i].index = i;
        cin >> ideas[i].value;
    }

    sort(
        contestants.begin(),
        contestants.end(),
        [](const auto& a, const auto& b) {
            return a.guess < b.guess;
        }
    );

    sort(
        ideas.begin(),
        ideas.end(),
        [](const auto& a, const auto& b) {
            return a.value < b.value;
        }
    );
    
    size_t i = 0;
    for (auto& idea : ideas) {
        while (i < n && contestants[i].guess <= idea.value) {
            i++;
        }
        idea.winner = i-1;
    }

    sort(
        ideas.begin(),
        ideas.end(),
        [](const auto& a, const auto& b) {
            return a.index < b.index;
        }
    );
    
    for (const auto& idea : ideas) {
        cout << (idea.winner < n ? contestants[idea.winner].name : ":(") << endl;
    }

    return 0;
}

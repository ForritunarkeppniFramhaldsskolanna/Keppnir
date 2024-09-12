#include "validate.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    size_t n, m, k;
    judge_in >> n >> m >> k;

    vector<size_t> popularities(n);
    string _;
    for (auto& pop : popularities) {
        judge_in >> _ >> pop;
    }

    sort(popularities.begin(), popularities.end());
    
    vector<size_t> cum_pop(n+1);
    for (size_t i = 0; i < n; i++) {
        cum_pop[i+1] = cum_pop[i] + popularities[i];
    }

    pair<size_t, size_t> mn{ m * cum_pop[n], 0ULL };
    for (size_t i{ 0ULL }; i < n; i++) {
        if (i + 1 < n && popularities[i] == popularities[i+1]) continue;
        const size_t cards{ popularities[i] };

        const size_t tickets{ cum_pop[n] - cum_pop[i + 1] - cards * (n - (i + 1)) };
        const size_t cur{ tickets * m + cards * k };
        mn = min(mn, {cur, cards});
    }
    
    int64_t author_cards_inp;
    if (!(author_out >> author_cards_inp)) {
        wrong_answer("Failed to read author number of cards.\n");
    }
    if (author_cards_inp < 0) {
        wrong_answer("Cannot buy a negative amount of cards.\n");
    }
    if (author_cards_inp > 1'000'000) {
        wrong_answer("Cannot buy more than 1'000'000 cards.\n");
    }
    size_t author_cards{ static_cast<size_t>(author_cards_inp) };
    
    size_t ind = 0;
    while (ind < n && popularities[ind] <= author_cards) ind++;
    size_t actual_total{ (cum_pop[n] - cum_pop[ind] - author_cards * (n - ind)) * m + author_cards * k };

    size_t author_total;
    if (!(author_out >> author_total)) {
        wrong_answer("Failed to read author total.\n");
    }
    if (actual_total != author_total) {
        wrong_answer("Author's reported card count does not match author's reported cost. Got %llu, expected %llu.\n", author_total, actual_total);
    }
    if (author_total != mn.first) {
        wrong_answer("Author reported total as %llu but should be %llu.\n", author_total, mn.first);
    }

    string s;
    author_out >> ws;
    if(author_out >> s) {
        wrong_answer("Trailing output.\n");
    }
    accept();
}

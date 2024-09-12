#include <algorithm>
#include <iostream>
#include <vector>
#include <x86intrin.h>
#include <cstring>

using namespace std;

constexpr int N{ 201'000 };
int guesses[N];
int linear_search(int arr[N], int key) {
    __m256i key8 = _mm256_set_epi32(key, key, key, key, key, key, key, key);
    for (size_t i = 0; i < N;) {
        auto nums{ _mm256_loadu_si256((__m256i*) (arr+i)) };
        auto cmp{ _mm256_cmpgt_epi32(nums, key8) };
        int res{ _mm256_movemask_epi8(cmp) };
        if (res) {
            return i + __builtin_ctz(res) / 4;
        }
        i += 8;
        nums = _mm256_loadu_si256((__m256i*) (arr+i));
        cmp = _mm256_cmpgt_epi32(nums, key8);
        res = _mm256_movemask_epi8(cmp);
        if (res) {
            return i + __builtin_ctz(res) / 4;
        }
        i += 8;
        nums = _mm256_loadu_si256((__m256i*) (arr+i));
        cmp = _mm256_cmpgt_epi32(nums, key8);
        res = _mm256_movemask_epi8(cmp);
        if (res) {
            return i + __builtin_ctz(res) / 4;
        }
        i += 8;
        nums = _mm256_loadu_si256((__m256i*) (arr+i));
        cmp = _mm256_cmpgt_epi32(nums, key8);
        res = _mm256_movemask_epi8(cmp);
        if (res) {
            return i + __builtin_ctz(res) / 4;
        }
        i += 8;
    }
    return N;
}

char names[12 * 200000];
struct contestant_t {
    int guess;
    char* name;
};


int main() {
    int n;
    auto _ = scanf("%d\n", &n);

    vector<contestant_t> contestants(n);
    char* at = names;
    for (auto& [guess, name] : contestants) {
        name = at;
        _ = scanf("%s %d\n", at, &guess);
        at += strlen(at) + 1;
    }
   
    sort(
        contestants.begin(),
        contestants.end(),
        [](const auto& a, const auto& b) {
            return a.guess < b.guess;
        }
    );

    for (int i = 0; i < n; i++) {
        guesses[i] = contestants[i].guess;
    }
    for (int i = n; i < n+256; i++) {
        guesses[i] = 2'000'000'000;
    }
    
    int q;
    _ = scanf("%d\n", &q);
    for (int i = 0; i < q; i++) {
        int idea;
        _ = scanf("%d\n", &idea);
        int ind = linear_search(guesses, idea) - 1;
        printf("%s\n", 0 <= ind && ind < n ? contestants[ind].name : ":(");
    }

    return 0;
}

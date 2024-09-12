#include <algorithm>
#include <iostream>
#include <vector>
#include <immintrin.h>

typedef int v4si __attribute__ ((vector_size (16)));
typedef short v8hi __attribute__ ((vector_size (16)));
typedef char v16qi __attribute__ ((vector_size (16)));

using namespace std;

constexpr int N{ 1<<3 };
int guesses[N];
#include <x86intrin.h>
int linear_search(int arr[N], int key) {
    __m128i key4 = _mm_set_epi32(key, key, key, key);

    for (size_t i = 0; i < N; i+=4) {
        __m128i nums = _mm_loadu_si128((__m128i*) (arr+i));
        __m128i cmp = _mm_cmplt_epi32(key4, nums);
        int res = _mm_movemask_epi8(cmp);
        if (res != 0xffff) {
            return i + __builtin_ctz(res) / 4 - 1;
        }
    }
    return N;
}

struct contestant_t {
    size_t guess;
    std::string name;
};


int main() {
    int n;
    cin >> n;

    vector<contestant_t> contestants(n);
    for (auto& [guess, name] : contestants) {
        cin >> name >> guess;
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
    for (int i = n; i < n+8; i++) {
        guesses[i] = 2'000'000'000;
    }
    
    size_t q;
    cin >> q;
    for (size_t i = 0; i < q; i++) {
        int idea;
        cin >> idea;
        int ind = linear_search(guesses, idea);
        cout << (ind < n ? contestants[ind].name : ":(") << endl;
    }

    return 0;
}

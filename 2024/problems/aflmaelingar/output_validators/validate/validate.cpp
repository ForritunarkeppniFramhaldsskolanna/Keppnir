#include <vector>
#include "validate.h"
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    int K, q, n = 300;
    judge_in >> K >> q;
    cout << K << ' ' << q << endl;

    int mod = 1;
    for(int i = 0; i < K; ++i)
        mod *= 10;

    vector<int> base(n);
    for(int i = 0; i < n; ++i)
        judge_in >> base[i];

    for(int i = 0; i < q; ++i) {
        vector<int> query(n);
        for(int j = 0; j < n; ++j) {
            if(!(author_out >> query[j])) {
                wrong_answer("Failed to read query.\n");
            }
        }
        int ans = 0;
        for(int j = 0; j < n; ++j) {
            ans += query[j] * base[j];
            ans %= mod;
        }
        cout << ans << endl;
    }
    for(int i = 0; i < n; ++i) {
        int ans_i;
        if(!(author_out >> ans_i)) {
            wrong_answer("Failed to read answer.\n");
        }
        if(ans_i != base[i]) {
            wrong_answer("Wrong answer.\n");
        }
    }
    string trash;
    if(author_out >> trash) wrong_answer("Trailing output.\n");
    accept();
}

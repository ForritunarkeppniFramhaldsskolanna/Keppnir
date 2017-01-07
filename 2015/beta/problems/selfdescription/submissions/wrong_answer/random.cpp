#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

template <class T> int size(const T &x) { return x.size(); }

int main() {

    srand(time(NULL));

    int n;
    cin >> n;

    int iters = 100000000 / n;
    int *arr = new int[n];
    int *cnt = new int[n];
    for (int i = 0; i < iters; i++) {
        memset(cnt, 0, n << 2);
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % n;
            cnt[arr[j]]++;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] != cnt[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            for (int i = 0; i < n; i++) {
                if (i != 0) {
                    printf(" ");
                }
                printf("%d", arr[i]);
            }
            printf("\n");
            return 0;
        }
    }

    printf("Engin\n");

    return 0;
}


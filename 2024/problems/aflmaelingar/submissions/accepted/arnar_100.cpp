#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int smod(int a, int b) {
    return (a + b) % b;
}

void write_arr(const vector<int>& arr) {
    for (const auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int query(const vector<int>& arr) {
    write_arr(arr);
    int response;
    cin >> response;
    return response;
}

int main() {
    int K, q;
    cin >> K >> q;

    int n = 300;
    vector<int> base_powers(n);
    if (K == 2) {
        for (int i = 0; i < q; i++) {
            vector<int> arr(n);
            arr[i] = 1;
            auto response{ query(arr) };
            base_powers[i] = response;
        }
    }
    else if (K == 3) {
        for (int i = 0; i < n / 3; i++) {
            vector<int> arr(n);
            arr[3 * i] = 1;
            arr[3 * i + 2] = 100;
            auto response{ query(arr) };
            base_powers[3 * i] = smod(response, 100);
            response -= base_powers[3 * i];
            base_powers[3 * i + 2] = response / 100;
            arr.assign(n, 0);
            arr[3 * i + 2] = 10;
            arr[3 * i + 1] = 1;
            response = query(arr);
            response -= base_powers[3 * i + 2] * 10;
            base_powers[3 * i + 1] = smod(response, 100);
            response -= base_powers[3 * i + 1];
            base_powers[3 * i + 2] += smod(response / 10, 100);
        }
    }
    else if (K == 4) {
        for (int i = 0; i < q; i++) {
            vector<int> arr(n);
            arr[2 * i] = 100;
            arr[2 * i + 1] = 1;
            auto response{ query(arr) };
            base_powers[2*i] = response / 100;
            base_powers[2*i+1] = smod(response, 100);
        }
    }

    write_arr(base_powers);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int bucket_answer = 0;
    int answer = 0;
    int bucket_size = sqrt(n);
    int no_of_buckets = (n + bucket_size - 1) / bucket_size;
    for (int bucket = 0; bucket < no_of_buckets; bucket++) {
        cout << "?";
        for (int j = 0; j < n; j++) {
            cout << " " << (j / bucket_size == bucket ? 1 : 0);
        }
        cout << endl;

        int response = 0;
        cin >> response;
        if (response % n != 0) {
            bucket_answer = bucket;
            break;
        }
    }

    for (int i = bucket_answer * bucket_size; i < min(n, (bucket_answer + 1) * bucket_size); i++) {
        cout << "?";
        for (int j = 0; j < n; j++) {
            cout << " " << (j == i ? 1 : 0);
        }
        cout << endl;
        
        int response = 0;
        cin >> response;
        if (response % n != 0) {
            answer = i + 1;
            break;
        }
    }

    cout << "! " << answer << endl;

    return 0;
}

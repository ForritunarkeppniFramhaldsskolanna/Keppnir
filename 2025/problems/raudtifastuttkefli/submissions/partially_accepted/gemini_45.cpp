#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> videos(n);
    for (int i = 0; i < n; ++i) {
        cin >> videos[i].first >> videos[i].second;
    }

    int total_time;
    cin >> total_time;

    long long max_dopamine = 0;

    if (n <= 20) {
        // Brute force for n <= 20 (Group 2)
        for (int i = 0; i < (1 << n); ++i) {
            long long current_dopamine = 0;
            long long current_time = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) { // If the j-th bit is set (watch the video)
                    if (current_time + videos[j].first <= total_time) {
                        current_time += videos[j].first;
                        current_dopamine += videos[j].second;
                    } else {
                        current_dopamine = 0;
                        break;
                    }
                } else { // Skip the video
                    if (current_time + k <= total_time) {
                        current_time += k;
                    } else {
                         current_dopamine = 0;
                        break;
                    }
                }
            }
            max_dopamine = max(max_dopamine, current_dopamine);
        }
    } else {
      //Dynamic Programming
      vector<long long> dp(total_time + 1, 0);
        for(int i = 0; i < n; i++){
            for(int j = total_time; j >= 0; --j){
                //Skip case
                if(j >= k){
                    dp[j] = max(dp[j], dp[j - k]);
                }
                //Watch case
                if(j >= videos[i].first){
                    dp[j] = max(dp[j], dp[j-videos[i].first] + videos[i].second);
                }
            }
        }
        max_dopamine = dp[total_time];
    }
    

    cout << max_dopamine << endl;

    return 0;
}

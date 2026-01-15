#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    int h, s;
    cin >> h >> s;

    vector<int> stations(n);
    for (int i = 0; i < n; ++i) {
        cin >> stations[i];
    }

    sort(stations.begin(), stations.end());

    long long total_time = 0;
    int current_water = x;
    int current_position = 0;

    if (n == 0) {
        total_time += (x / h);
          current_position = x;
        total_time += (42195 - x) /s;
          
    }
    else{
      
    
    for (int i = 0; i < n; ++i) {
        int distance_to_station = stations[i] - current_position;

        if (current_water >= distance_to_station) {
            total_time += (long long)distance_to_station / h;
            current_water -= distance_to_station;
        } else {
            total_time += (long long)current_water / h;
            distance_to_station -= current_water;
            current_water = 0;
            total_time += (long long)distance_to_station / s;
        }

        current_position = stations[i];
        current_water = x;
        total_time += y;
    }

    int remaining_distance = 42195 - current_position;
    if (current_water >= remaining_distance) {
        total_time += (long long)remaining_distance / h;
    } else {
      
        total_time += (long long)current_water / h;
            remaining_distance -= current_water;
        total_time += (long long)remaining_distance / s;
    }
      
    }

    int hours = total_time / 3600;
    int minutes = (total_time % 3600) / 60;
    int seconds = total_time % 60;

    cout << setfill('0') << setw(2) << hours << ":"
         << setfill('0') << setw(2) << minutes << ":"
         << setfill('0') << setw(2) << seconds << endl;

    return 0;
}

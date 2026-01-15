#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Assignment {
    long long assign_day;
    long long due_day;
    long long time_needed;
};

bool can_finish(const vector<Assignment>& assignments, long long work_per_day) {
    vector<pair<long long, long long>> schedule; // (day, work_to_do)
    for (const auto& assignment : assignments) {
        schedule.push_back({assignment.assign_day, assignment.time_needed});
        schedule.push_back({assignment.due_day + 1, -assignment.time_needed});
    }
    sort(schedule.begin(), schedule.end());

    long long current_workload = 0;
    long long current_day = 0;
    for (const auto& event : schedule) {
        if (event.first > current_day) {
            long long days_passed = event.first - current_day;
            if (current_workload > days_passed * work_per_day) {
                return false;
            }
            current_day = event.first;
        }
        current_workload += event.second;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Assignment> assignments(n);
    for (int i = 0; i < n; ++i) {
        cin >> assignments[i].assign_day >> assignments[i].due_day >> assignments[i].time_needed;
    }

    long long low = 0;
    long long high = 1e15; 
    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can_finish(assignments, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}

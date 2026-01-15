#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent a dart throw
struct Throw {
    int points;
    string description;
};

// Function to generate all possible single dart throws
vector<Throw> generate_throws() {
    vector<Throw> throws;

    // Bullseye
    throws.push_back({50, "Bullseye"});

    // Outer Bullseye
    throws.push_back({25, "Outer bullseye"});

    // Singles, Doubles, and Triples
    for (int i = 1; i <= 20; ++i) {
        throws.push_back({i, "Single " + to_string(i)});
        throws.push_back({2 * i, "Double " + to_string(i)});
        throws.push_back({3 * i, "Triple " + to_string(i)});
    }

    return throws;
}

int main() {
    int x;
    cin >> x;

    vector<Throw> all_throws = generate_throws();
    vector<vector<Throw>> solutions;

    // One throw solutions
    for (const auto& throw1 : all_throws) {
        if (throw1.points == x) {
            solutions.push_back({throw1});
        }
    }

    // Two throw solutions
    for (const auto& throw1 : all_throws) {
        for (const auto& throw2 : all_throws) {
            if (throw1.points + throw2.points == x) {
                solutions.push_back({throw1, throw2});
            }
        }
    }

    // Three throw solutions
    for (const auto& throw1 : all_throws) {
        for (const auto& throw2 : all_throws) {
            for (const auto& throw3 : all_throws) {
                if (throw1.points + throw2.points + throw3.points == x) {
                    solutions.push_back({throw1, throw2, throw3});
                }
            }
        }
    }
    
    
    vector<vector<string>> string_solutions;
    for(const auto& solution : solutions){
        vector<string> string_solution;
        for(const auto& thr : solution){
            string_solution.push_back(thr.description);
        }
        sort(string_solution.begin(), string_solution.end());
        string_solutions.push_back(string_solution);
    }
        
    sort(string_solutions.begin(), string_solutions.end());
    string_solutions.erase(unique(string_solutions.begin(), string_solutions.end()), string_solutions.end());
        

    cout << string_solutions.size() << endl;

     for(const auto& solution : solutions){
        vector<string> string_solution;
        for(const auto& thr : solution){
            string_solution.push_back(thr.description);
        }
        sort(string_solution.begin(), string_solution.end());
          bool printed = false;
        for(const auto& sol : string_solutions){
            if (sol == string_solution && !printed){
                 cout << solution.size() << endl;
                for (const auto& thr : solution) {
                cout << thr.description << endl;
                 }
                printed=true;
            }
        }

    }


    return 0;
}

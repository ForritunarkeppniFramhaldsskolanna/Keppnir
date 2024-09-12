#include "validate.h"
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n;
    judge_in >> n;
    vector<string> names(n);
    vector<string> ordering;
    for (auto& name: names) {
        judge_in >> name;
    }
    
    for(int i = 0; i < n; ++i) {
        string ans;
        if(!(author_out >> ans)) {
            wrong_answer("Failed to read %d-th name in output.\n", i + 1);
        }
        if(find(names.begin(), names.end(), ans) == names.end()) {
            wrong_answer("%d-th name given is not in input.\n", i + 1);
        }
        if(find(ordering.begin(), ordering.end(), ans) != ordering.end()) {
            wrong_answer("Duplicate name %s in output.\n", ans.c_str());
        }
        ordering.push_back(ans);
    }
    
    size_t idx{ 12ull % n };
    string expected{ names[0] };
    string actual{ ordering[idx] };


    if (strcasecmp(expected.c_str(), actual.c_str()) != 0) {
        wrong_answer("Expected to find %s at index %d but found %s.\n", expected.c_str(), idx, actual.c_str()); 
    }

    string s;
    author_out >> ws;
    if(author_out >> s) {
        wrong_answer("Trailing output.\n");
    }
    accept();
}

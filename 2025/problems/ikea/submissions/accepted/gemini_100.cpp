#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

struct Item {
    std::string name;
    int weight;
    int original_index;
};

bool compareItems(const Item& a, const Item& b) {
    if (a.weight != b.weight) {
        return a.weight < b.weight;
    }
    return a.original_index < b.original_index;
}

bool compareNames(const Item& a, const Item& b) {
    return a.name < b.name;
}

int main() {
    int k, n;
    std::cin >> k >> n;

    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> items[i].name >> items[i].weight;
        items[i].original_index = i;
    }

    std::sort(items.begin(), items.end(), compareItems);

    int num_items_dagur = std::floor((double)n / k);
    int num_items_dagur_ceil = std::ceil((double)n / k);

    long long weight_floor = 0;
    for (int i = 0; i < num_items_dagur; ++i) {
        weight_floor += items[i].weight;
    }

    long long weight_ceil = 0;
    for (int i = 0; i < num_items_dagur_ceil; ++i)
        weight_ceil += items[i].weight;
    

    long long weight_next_floor = 0;
     if (n >= num_items_dagur_ceil + num_items_dagur){
        for(int i = num_items_dagur_ceil; i < num_items_dagur_ceil + num_items_dagur; i++)
        {
            weight_next_floor += items[i].weight;
        }
     }


    std::vector<Item> dagur_items;
    if (num_items_dagur_ceil + num_items_dagur <= n && weight_ceil < weight_next_floor ) {
        for (int i = 0; i < num_items_dagur_ceil; ++i) {
            dagur_items.push_back(items[i]);
        }
        std::cout << weight_ceil << std::endl;
    } else {
        for (int i = 0; i < num_items_dagur; ++i) {
            dagur_items.push_back(items[i]);
        }
        std::cout << weight_floor << std::endl;
    }

    std::sort(dagur_items.begin(), dagur_items.end(), compareNames);

    for (const auto& item : dagur_items) {
        std::cout << item.name << std::endl;
    }

    return 0;
}

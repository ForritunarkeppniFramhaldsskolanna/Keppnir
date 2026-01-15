#include<iostream>

int main() {
    int n; std::cin >> n;
    int ans = n;
    while(n--) {
        int x; std::cin >> x;
        ans = std::max(ans, x);
    }
    std::cout << ans << '\n';
}

#include <iostream>
int main(){
    std::cin.sync_with_stdio(false);
    int n;
    std::cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)      std::cin >> a[i];
    for(int i = n - 1; i >= 0; i--) std::cout << a[i] << std::endl;
    delete [] a;
}

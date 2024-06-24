#include <iostream>

int main() {
    int arrn[10001];
    int n, x;
    std::cin >> n >> x;
    for (int i = 0; i < n; i++) {
        std::cin >> arrn[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(arrn[i] < x)
            std::cout<<arrn[i] << " ";
    }
    
    return 0;
}
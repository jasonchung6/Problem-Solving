#include <iostream>

int main() {
    int t, h, w, n;
    int nh, nw;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> h >> w >> n;
        nw = n / h + 1;
        nh = n % h;
        if (nh == 0) {
            nh = h;
            nw--;
        }
        std::cout << nh;
        if (nw < 10) std::cout << 0;
        std::cout << nw << "\n";
    }
}
#include <iostream>

int main() {
    int num, mod[10], cnt = 10;
    for (int i = 0; i < 10; i++) {
        std::cin >> num;
        mod[i] = num % 42;
        for (int j = 0; j < i; j++) {
            if (mod[i] == mod[j]) {
                cnt--;
                break;
            }
        }
    }
    std::cout << cnt;
}

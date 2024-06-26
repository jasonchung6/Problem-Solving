#include <iostream>

int main() {
    int pitch;
    bool ascending = 1, descending = 1;
    for (int i = 1; i < 9; i++) {
        std::cin >> pitch;
        if (pitch == i && ascending == 1) {
            ascending = 1;
            descending = 0;
        } else if (pitch == 9 - i && descending == 1) {
            descending = 1;
            ascending = 0;
        } else {
            ascending = 0;
            descending = 0;
        }
    }
    if (ascending == 1)
        std::cout << "ascending";
    else if (descending == 1)
        std::cout << "descending";
    else
        std::cout << "mixed";
}

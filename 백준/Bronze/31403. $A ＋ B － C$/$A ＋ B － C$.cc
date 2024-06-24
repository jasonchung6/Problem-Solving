#include <iostream>
#include <string>

int main() {
    int a, b, c;
    std::string str;
    std::cin >> a >> b >> c;
    std::cout << a + b - c << "\n";
    str = std::to_string(a) + std::to_string(b);
    a = stoi(str);
    std::cout << a - c;
    return 0;
}
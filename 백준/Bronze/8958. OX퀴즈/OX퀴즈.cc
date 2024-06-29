#include <iostream>
#include <string>

int main() {
    int test, score, cont, str_size;
    std::string str;
    std::cin >> test;
    for (int i = 0; i < test; i++) {
        std::cin >> str;
        str_size = str.length();
        cont = 0;
        score = 0;
        for (int j = 0; j < str_size; j++) {
            if (str.at(j) == 'O') {
                cont++;
                score += cont;
            } else
                cont = 0;
        }
        std::cout << score << "\n";
    }
}
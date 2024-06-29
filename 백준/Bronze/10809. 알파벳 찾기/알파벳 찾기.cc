#include <string.h>
#include <iostream>

int main() {
    int idx[26];
    for (int i = 0; i < 26; i++) {
        idx[i] = -1;
    }
    char arr[101];
    std::cin >> arr;
    for (int i = 0; i < strlen(arr); i++) {
        if (idx[arr[i] - 97] == -1) idx[arr[i] - 97] = i;
    }

    for (int i = 0; i < 26; i++) {
        std::cout << idx[i] << " ";
    }
}
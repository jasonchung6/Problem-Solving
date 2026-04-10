#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    int i;
    cin >> str1 >> i;
    cout << str1.at(i-1);

    return 0;
}
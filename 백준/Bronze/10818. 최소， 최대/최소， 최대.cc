#include <iostream>
using namespace std;

int main() {
    int n = 0, input = 0, min = 1000000, max = -1000000;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input < min)
            min = input;
        if (input > max)
            max = input;
    }
    cout << min << " " << max;

    return 0;
}
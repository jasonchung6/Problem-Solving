#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, idx, diff = 0;
    double sum = 0;
    cin >> n;
    if (n == 0) {
        cout << diff;
        return 0;
    }
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num.begin(), num.end());
    idx = round(n * 0.15);
    for (int i = idx; i < n - idx; i++) sum += num[i];
    diff = round(sum / (n - idx * 2));
    cout << diff;
    return 0;
}
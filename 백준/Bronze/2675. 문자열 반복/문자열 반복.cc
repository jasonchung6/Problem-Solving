#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, mul;
    string str1, ans;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> mul >> str1;
        for (int j = 0; j < str1.size() * mul; j++)
            ans += str1.at(j / mul);
        cout << ans <<'\n';
        ans.erase();
    }
}
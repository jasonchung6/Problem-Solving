#include <iostream>
using namespace std;

int main() {

    int n = 0, people = 0, apple = 0, nam = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> people >> apple;
        nam += apple % people;
    }
    cout << nam;
    return 0;
}
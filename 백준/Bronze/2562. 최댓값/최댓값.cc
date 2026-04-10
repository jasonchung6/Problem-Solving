#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec1(10);
    int max = 0, num = 0;
    for (int i = 1; i < 10; i++)
    {
        cin >> vec1[i];
        if (vec1[i] > max)
        {
            max = vec1[i];
            num = i;
        }
    }
        cout << max << "\n" << num;
}
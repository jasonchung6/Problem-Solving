#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> vec[i][0] >> vec[i][1];

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++)
        cout << vec[i][0] << " " << vec[i][1] << "\n";

    return 0;
}
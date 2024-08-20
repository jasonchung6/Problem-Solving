#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tri(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++)
            cin >> tri[i][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }

    cout << tri[0][0] << endl;

    return 0;
}
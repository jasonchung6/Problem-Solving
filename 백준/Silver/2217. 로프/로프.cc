#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> rope(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end(), [](int& a, int& b) {return a > b; });

    int maxW = 0;

    for (int i = 0; i < N; i++)
    {
        maxW = max((rope[i] * (i + 1)), maxW);
    }

    cout << maxW;

	return 0;
}
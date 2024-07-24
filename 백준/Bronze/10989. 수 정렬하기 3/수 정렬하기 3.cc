#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
constexpr int SIZE = 10001;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, temp;
    cin >> n;
    vector<int> vec(SIZE);

    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        vec[temp]++;
    }
    for (int i = 1; i < SIZE; ++i)
    {
        while (vec[i])
        {
            cout << i << "\n";
            vec[i]--;
        }
    }

	return 0;
}
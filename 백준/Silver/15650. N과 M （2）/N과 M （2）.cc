#include <iostream>
#include <vector>
using namespace std;

int N, M;

void backtrack(int start, vector<int> combination)
{
    if (combination.size() == M)
    {
        for (const int &num : combination)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; ++i)
    {
        combination.push_back(i);
        backtrack(i + 1, combination);
        combination.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<int> combination;
    backtrack(1, combination);

    return 0;
}
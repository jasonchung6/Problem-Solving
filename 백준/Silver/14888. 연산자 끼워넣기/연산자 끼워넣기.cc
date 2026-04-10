#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 1e9;
constexpr int SIZE = 101;
vector<int> A(SIZE, 0);
int N;
int MAX = -INF;
int MIN = INF;
int sym[4]; // +-*/

void dfs(int num, int idx)
{
    if (idx == N)
    {
        if (num > MAX)
        {
            MAX = num;
        }
        if (num < MIN)
        {
            MIN = num;
        }
        return;
    }

    if (sym[0] > 0)
    {
        --sym[0];
        dfs(num + A[idx], idx + 1);
        ++sym[0];
    }
    if (sym[1] > 0)
    {
        --sym[1];
        dfs(num - A[idx], idx + 1);
        ++sym[1];
    }
    if (sym[2] > 0)
    {
        --sym[2];
        dfs(num * A[idx], idx + 1);
        ++sym[2];
    }
    if (sym[3] > 0)
    {
        --sym[3];
        dfs(num / A[idx], idx + 1);
        ++sym[3];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    cin >> sym[0] >> sym[1] >> sym[2] >> sym[3];
    dfs(A[0], 1);

    cout << MAX << '\n'
         << MIN;

    return 0;
}
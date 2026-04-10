#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

using ll = long long;
constexpr int INF = numeric_limits<int>::max();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m;
    ll ANS = 0;
    cin >> T >> n;
    vector<int> A(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
        A[i] += A[i - 1];
    }
    cin >> m;
    vector<int> B(m + 1, 0);
    for (int i = 1; i <= m; ++i)
    {
        cin >> B[i];
        B[i] += B[i - 1];
    }

    vector<int> addA;
    vector<int> addB;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            addA.push_back(A[i] - A[j]);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            addB.push_back(B[i] - B[j]);
        }
    }

    sort(addA.begin(), addA.end());
    sort(addB.begin(), addB.end());
    addA.push_back(INF);
    addB.push_back(INF);

    ll cntA = 0;
    for (int i = 0; i < addA.size(); ++i)
    {
        if (addA[i] == addA[i + 1])
        {
            ++cntA;
            continue;
        }
        else
        {
            ++cntA;
            ll cntB = upper_bound(addB.begin(), addB.end(), T - addA[i]) - lower_bound(addB.begin(), addB.end(), T - addA[i]);
            ANS += cntA * cntB;
            cntA = 0;
        }
    }

    cout << ANS;

    return 0;
}
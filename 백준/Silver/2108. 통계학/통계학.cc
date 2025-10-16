#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    double sum = 0;
    int index[8001] = {
        0,
    };
    int max_count = 0;
    queue<int> q;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
        sum += v[i];
        ++index[v[i] + 4000];
    }
    for (int i = 0; i < 8001; ++i)
    {
        if (index[i] > max_count)
        {
            max_count = index[i];
            q = queue<int>();
            q.push(i);
        }
        else if (index[i] == max_count)
        {
            q.push(i);
        }
    }
    if (q.size() > 1)
    {
        q.pop();
    }
    sort(v.begin(), v.end());
    cout << lround(sum / N) << '\n'
         << v[N / 2] << '\n'
         << q.front() - 4000 << '\n'
         << v[N - 1] - v[0];
    return 0;
}
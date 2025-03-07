#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0;
    cin >> N;
    vector<pair<int, int>> cls(N, { 0,0 });
    priority_queue<int, vector<int>, greater<int>> PQ;
    int numOfRoom = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> cls[i].first >> cls[i].second;
    }

    sort(cls.begin(), cls.end(), [](const auto& a, const auto& b) {return a.first < b.first; });

    bool needNewRoom = 1;
    for (int i = 0; i < N; ++i)
    {
        PQ.push(cls[i].second);

        if (cls[i].first >= PQ.top())
        {
            PQ.pop();
        }
    }

    cout << PQ.size();

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Pii = pair<int, int>;
int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<Pii> edges[N + 1];
    vector<bool> visited(N + 1, 0);
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
    }

    priority_queue<Pii, vector<Pii>, greater<Pii>> pq;
    pq.push({0, 1});
    int result = 0;
    int cnt = 0;

    while (!pq.empty())
    {
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur])
            continue;

        visited[cur] = 1;
        result += w;
        ++cnt;

        if (cnt == N)
            break;

        for (auto &next : edges[cur])
        {
            if (!visited[next.second])
            {
                pq.push(next);
            }
        }
    }

    cout << result;

    return 0;
}
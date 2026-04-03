#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Pii = pair<int, int>;
constexpr int INF = 1e9;
vector<vector<Pii>> graph;
vector<int> dist;

int N, E;
int v1, v2;

void dijkstra(int source)
{
    priority_queue<Pii, vector<Pii>, greater<Pii>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (cost != dist[u])
        {
            continue;
        }

        for (const auto &edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;
    graph.assign(N + 1, vector<Pii>());

    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    int ANS = INF;
    bool hasANS = 0;

    dist.assign(N + 1, INF);
    dist[1] = 0;
    dijkstra(1);
    vector<int> dist1 = dist;

    dist.assign(N + 1, INF);
    dist[v1] = 0;
    dijkstra(v1);
    vector<int> dist_v1 = dist;

    dist.assign(N + 1, INF);
    dist[v2] = 0;
    dijkstra(v2);
    vector<int> dist_v2 = dist;

    if (dist_v1[v2] == INF)
    {
        cout << -1;
        return 0;
    }
    if (dist1[v2] != INF && dist_v1[N] != INF)
    {
        hasANS = 1;
        ANS = min(ANS, dist1[v2] + dist_v2[v1] + dist_v1[N]);
    }
    if (dist1[v1] != INF && dist_v2[N] != INF)
    {
        hasANS = 1;
        ANS = min(ANS, dist1[v1] + dist_v1[v2] + dist_v2[N]);
    }

    if (hasANS)
    {
        cout << ANS;
    }
    else
    {
        cout << -1;
    }

    return 0;
}
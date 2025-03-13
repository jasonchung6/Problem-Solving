#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

constexpr int INF = numeric_limits<int>::max();

void dijkstra(int source, vector<vector<pair<int, int>>>& graph, vector<int>& dist)
{
    int n = graph.size();
    dist.assign(n, INF);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, source });

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curCost != dist[u])
        {
            continue;
        }

        for (const auto& edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, source, dest;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int cost;
        cin >> source >> dest >> cost;
        graph[source].push_back({ dest, cost });
    }
    cin >> source >> dest;

    vector<int> dist;
    dijkstra(source, graph, dist);
    
    cout << dist[dest];

	return 0;
}
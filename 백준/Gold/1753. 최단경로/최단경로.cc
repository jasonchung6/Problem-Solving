#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//constexpr int INF = numeric_limits<int>::max();
constexpr int INF = 100'000'001;

void dijkstra()
{

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, E, start;
	cin >> V >> E >> start;
	vector<vector<pair<int, int>>> graph(V + 1);
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	vector<int> dist(V + 1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int w = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (w > dist[u])
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

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << dist[i] << '\n';
		}
	}

	return 0;
}
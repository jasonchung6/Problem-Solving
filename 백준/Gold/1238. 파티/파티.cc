#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

constexpr int INF = numeric_limits<int>::max();
#define pii pair<int, int>

void dijkstra(int src, vector<vector<pii>> &graph, vector<int> &dist)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({src, 0});

	while (!pq.empty())
	{
		int u = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();

		if (cur_cost != dist[u])
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
				pq.push({v, dist[v]});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, X;
	cin >> N >> M >> X;
	vector<vector<pii>> graph(N + 1);
	vector<vector<pii>> reverse_graph(N + 1);
	vector<int> dist_to_x(N + 1, INF);
	vector<int> dist_from_x(N + 1, INF);
	dist_to_x[X] = 0;
	dist_from_x[X] = 0;
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		reverse_graph[v].push_back({u, w});
	}

	dijkstra(X, reverse_graph, dist_to_x);
	dijkstra(X, graph, dist_from_x);

	int ANS = 0;
	for (int i = 0; i <= N; ++i)
	{
		if (ANS < dist_from_x[i] + dist_to_x[i])
		{
			ANS = dist_from_x[i] + dist_to_x[i];
		}
	}

	cout << ANS;
	return 0;
}
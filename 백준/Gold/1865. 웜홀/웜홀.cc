#include <iostream>
#include <vector>
#include <limits>
#include <tuple>
using namespace std;

#define pii pair<int, int>
constexpr int INF = numeric_limits<int>::max();

bool bellmanFord(int V, int start, vector<tuple<int, int, int>> &edges, vector<int> &dist)
{
	dist.assign(V + 1, INF);
	dist[start] = 0;

	for (int i = 1; i <= V - 1; ++i)
	{
		for (auto [u, v, w] : edges)
		{
			if (dist[u] != INF && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
			}
		}
	}

	for (auto [u, v, w] : edges)
	{
		if (dist[u] != INF && dist[v] > dist[u] + w)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;
	for (int i = 0; i < TC; ++i)
	{
		int N, M, W;
		cin >> N >> M >> W;
		vector<tuple<int, int, int>> edges;
		vector<int> dist;

		for (int j = 1; j <= N; ++j)
		{
			edges.push_back({0, j, 0});
		}

		for (int j = 0; j < M; ++j)
		{
			int S, E, T;
			cin >> S >> E >> T;
			edges.push_back({S, E, T});
			edges.push_back({E, S, T});
		}
		for (int j = 0; j < W; ++j)
		{
			int S, E, T;
			cin >> S >> E >> T;
			edges.push_back({S, E, -T});
		}
		if (bellmanFord(N, 0, edges, dist))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
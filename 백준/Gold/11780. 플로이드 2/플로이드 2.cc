#include <iostream>
#include <vector>
using namespace std;

//constexpr int INF = numeric_limits<int>::max();
constexpr int INF = 100'000'001;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	vector<vector<int>> route(n + 1, vector<int>(n + 1, -1));
	for (int i = 1; i <= n; ++i)
	{
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		dist[start][end] = min(dist[start][end], cost);
		route[start][end] = end;
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (dist[i][k] != INF)
			{
				for (int j = 1; j <= n; ++j)
				{
					if (dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						route[i][j] = route[i][k];
					}
				}

			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dist[i][j] == INF)
			{
				cout << "0 ";
			}
			else
			{
				cout << dist[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (route[i][j] == -1)
			{
				cout << '0';
			}
			else
			{
				vector<int> path{ i };
				int start = i, end = j;
				while (start != end)
				{
					start = route[start][end];
					path.push_back(start);
				}
				cout << path.size() << ' ';
				for (int k = 0; k < path.size(); ++k)
				{
					cout << path[k] << ' ';
				}
			}
			cout << '\n';
		}
	}

	return 0;
}
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
	for (int i = 1; i <= n; ++i)
	{
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		dist[start][end] = min(dist[start][end], cost);
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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

	return 0;
}
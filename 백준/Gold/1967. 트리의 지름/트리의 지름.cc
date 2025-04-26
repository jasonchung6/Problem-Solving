#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> node;
vector<bool> visited;
int maxVal, cnt, maxLeaf;

void dfs(int num)
{
	visited[num] = 1;
	for (int i = 0; i < node[num].size(); ++i)
	{
		if (visited[node[num][i].first] == 0)
		{
			cnt += node[num][i].second;
			if (cnt > maxVal)
			{
				maxVal = cnt;
				maxLeaf = node[num][i].first;
			}
			dfs(node[num][i].first);
			cnt -= node[num][i].second;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	node.assign(n + 1, vector<pair<int, int>>());
	visited.assign(n + 1, 0);
	for (int i = 1; i < n; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back({ v, w });
		node[v].push_back({ u, w });
	}



	dfs(1);
	visited.assign(n + 1, 0);
	dfs(maxLeaf);

	cout << maxVal;

	return 0;
}
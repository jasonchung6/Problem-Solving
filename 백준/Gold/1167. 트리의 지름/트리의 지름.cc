#include <iostream>
#include <vector>

using namespace std;

#define pii pair<int,int>
int max_dis;
int max_u;

void dfs(int u, int dis, const vector<vector<pii>>& tree, vector<bool>& visited) {
	for (const auto& v : tree[u]) {
		if (!visited[v.first]) {
			visited[v.first] = true;
			int vdis = dis + v.second;
			if (vdis > max_dis) {
				max_dis = vdis;
				max_u = v.first;
			}
			dfs(v.first, dis + v.second, tree, visited);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V;
	cin >> V;
	vector<vector<pii>> tree(V + 1);
	vector<bool> visited(V + 1, false);

	for (int i = 0; i < V; ++i) {
		int u;
		cin >> u;
		int v, w;
		while (1) {
			cin >> v;
			if (v == -1) {
				break;
			}
			cin >> w;
			tree[u].push_back({ v,w });
		}
	}

	visited[1] = true;
	dfs(1, 0, tree, visited);

	max_dis = 0;
	visited.assign(V + 1, false);
	visited[max_u] = true;
	dfs(max_u, 0, tree, visited);
	cout << max_dis;

	return 0;
}
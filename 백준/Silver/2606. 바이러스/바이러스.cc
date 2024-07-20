#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int SIZE = 101;
vector <int> vec[SIZE];
vector <bool> visited(SIZE,0);
queue<int> q;

int dfs(int v) {
	int node, ans = 0;
	visited[v] = 1;
	q.push(v);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int nei : vec[node]) {
			if (!visited[nei])
			{
				q.push(nei);
				visited[nei] = 1;
				++ans;
			}
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, a,b;
	cin >> n >> m;

	while (m--) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	cout << dfs(1);

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'

constexpr int SIZE = 1001;
vector<int> vec[SIZE];
vector<bool> visited;

void dfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	cout << v << " ";
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int neighbor : vec[node]) {
			if (!visited[neighbor])
			{
				q.push(neighbor);
				visited[neighbor] = 1;
				dfs(neighbor);
			}
		}
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int neighbor : vec[node]) {
			if (!visited[neighbor])
			{
				q.push(neighbor);
				visited[neighbor] = 1;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, v, n1, n2;
	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i) {
		cin >> n1 >> n2;
		vec[n1].push_back(n2);
		vec[n2].push_back(n1);
	}

	for (int i = 1; i < SIZE; ++i)
		if (!vec[i].empty())
			sort(vec[i].begin(), vec[i].end());

	visited.assign(SIZE, 0);
	dfs(v);
	cout << endl;
	visited.assign(SIZE, 0);
	bfs(v);

	return 0;
}
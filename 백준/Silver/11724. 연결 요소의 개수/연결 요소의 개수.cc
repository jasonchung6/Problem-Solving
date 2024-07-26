#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int SIZE = 1000;
vector<int> vec[SIZE];
vector<bool> visited(SIZE, 0);
queue<int> q;

void dfs(int n)
{
	int node;
	q.push(n);
	visited[n] = true;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		for (auto elem : vec[node])
		{
			if (!visited[elem])
			{
				visited[elem] = true;
				q.push(elem);
				dfs(elem);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, ans = 0;
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)
		if (!visited[i])
		{
			dfs(i);
			++ans;
		}

	cout << ans;

	return 0;
}
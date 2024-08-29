#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
constexpr int SIZE = 100'001;
vector<int> tree[SIZE];
vector<int> ans(SIZE);
queue<int> q;

void dfs() {
	int node = 1;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < tree[node].size(); i++)
		{
			if (ans[tree[node][i]] == 0)
			{
				q.push(tree[node][i]);
				ans[tree[node][i]] = node;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	ans[1] = 1;
	dfs();

	for (int i = 2; i <= n; i++)
		cout << ans[i] << endl;

	return 0;
}
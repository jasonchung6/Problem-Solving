#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> student(N + 1);
	vector<int> indgree(N + 1, 0);
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		student[a].push_back(b);
		++indgree[b];
	}

	queue<int> q;
	queue<int> ans;
	for (int i = 1; i <= N; ++i)
	{
		if (indgree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		ans.push(cur);
		q.pop();
		for (const int &next : student[cur])
		{
			--indgree[next];
			if (indgree[next] == 0)
			{
				q.push(next);
			}
		}
	}

	while (!ans.empty())
	{
		cout << ans.front() << ' ';
		ans.pop();
	}

	return 0;
}

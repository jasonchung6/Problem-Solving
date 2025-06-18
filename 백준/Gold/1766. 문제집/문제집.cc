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
	vector<vector<int>> problem(N + 1);
	vector<int> indegree(N + 1, 0);
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		problem[A].push_back(B);
		++indegree[B];
	}

	priority_queue<int, vector<int>, greater<int>> q;
	queue<int> ans;
	for (int i = 1; i <= N; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.top();
		ans.push(cur);
		q.pop();

		for (const int &next : problem[cur])
		{
			if (--indegree[next] == 0)
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

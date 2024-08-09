#include <iostream>
using namespace std;

#define endl '\n'
constexpr int SIZE = 9;
int n, m;
int ans[SIZE];
bool visited[SIZE];

void dfs(int cnt) {
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << endl;
		return;
	}
	else {
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				visited[i] = 1;
				ans[cnt] = i;
				dfs(cnt + 1);
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	dfs(0);

	return 0;
}
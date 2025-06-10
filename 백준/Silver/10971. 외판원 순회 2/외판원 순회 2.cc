#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 1e9;

int N;
vector<vector<int>> cost;
vector<vector<int>> dp;

int tsp(int cur, int visited)
{
	if (visited == (1 << N) - 1)
	{
		if (cost[cur][0] == 0)
		{
			return INF;
		}
		return cost[cur][0];
	}
	if (dp[cur][visited] != -1)
	{
		return dp[cur][visited];
	}

	int &result = dp[cur][visited];
	if (result != -1)
	{
		return result;
	}

	result = INF;
	for (int next = 0; next < N; ++next)
	{
		if ((visited & (1 << next)) == 0 && cost[cur][next] != 0)
		{
			result = min(result, tsp(next, visited | (1 << next)) + cost[cur][next]);
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	cost.assign(N + 1, vector<int>(N + 1, 0));
	dp.assign(N + 1, vector<int>(1 << N, -1));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> cost[i][j];
		}
	}

	cout << tsp(0, 1);

	return 0;
}
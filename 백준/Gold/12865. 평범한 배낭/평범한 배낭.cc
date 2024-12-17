#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int SIZE = 101;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	int weight[SIZE] = { 0, };
	int value[SIZE] = { 0, };
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

	int w, v;
	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= weight[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			} else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];

	return 0;
}
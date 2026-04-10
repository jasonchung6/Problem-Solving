#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	int N, T;
	cin >> N >> T;
	vector<int> time(N + 1);
	vector<int> score(N + 1);
	vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));
	for (int i = 1; i <= N; ++i)
	{
		cin >> time[i] >> score[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= T; ++j)
		{
			if (j >= time[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + score[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][T];

 	return 0;
}
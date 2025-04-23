#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[n][m] << '\n';

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	string ans;
	int i = n;
	int j = m;
	while (i > 0 && j > 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			ans += s1[i - 1];
			--i;
			--j;
		}
		else
		{
			if (dp[i - 1][j] > dp[i][j - 1])
			{
				--i;
			}
			else
			{
				--j;
			}
		}
	}

	string temp = ans;
	int ansLen = ans.length();
	for (int i = 0; i < ansLen; ++i)
	{
		ans[i] = temp[ansLen - i - 1];
	}
	cout << ans;

	return 0;
}
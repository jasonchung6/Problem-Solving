#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, temp, min = 0, ans = 0;
	int dp[1001][2] = { 0, };
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> dp[i][0];
		++dp[i][1];
		for (int j = 0; j < i; j++)
		{
			if (dp[j][0] < dp[i][0])
			{
				if (dp[j][1] >= dp[i][1])
					dp[i][1] = dp[j][1] + 1;
			}
		}

	}

	for (int i = 0; i < n; i++)
		if (ans < dp[i][1])
			ans =dp[i][1];

	cout << ans;

	return 0;
}
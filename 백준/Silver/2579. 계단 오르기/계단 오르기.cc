#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> vec(n, 0);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> vec[i];

	dp[0] = vec[0];
	dp[1] = vec[0] + vec[1];
	dp[2] = max(vec[0]+vec[2],vec[1]+vec[2]);

	for (int i = 3; i < n; ++i)
		dp[i] = max(dp[i - 2] + vec[i], vec[i - 1]+vec[i] + dp[i-3]);

	cout << dp[n-1];

	return 0;
}
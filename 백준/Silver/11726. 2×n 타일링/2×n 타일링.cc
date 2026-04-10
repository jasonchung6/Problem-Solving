#include <iostream>
using namespace std;

#define endl '\n'
//constexpr int SIZE = 1001;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int temp, dp[1001] = { 0, };
	cin >> temp;
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < temp; ++i)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;

	cout << dp[temp - 1];

	return 0;
}
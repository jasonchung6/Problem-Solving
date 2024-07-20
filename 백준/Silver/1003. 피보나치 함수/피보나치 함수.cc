#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
constexpr int SIZE = 41;

int fibonacci(int n) {
	if (n == 0) {
		printf("0");
		return 0;
	}
	else if (n == 1) {
		printf("1");
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		if (n == 0) {
			cout << 1 << ' ' << 0 << endl;
			continue;
		}
		else if (n == 1) {
			cout << 0 << ' ' << 1 << endl;
			continue;
		}
		int dp0[3] = { 1,0,0 };
		int dp1[3] = { 0,1,0 };
		for (int i = 2; i <= n; ++i)
		{
			dp0[2] = dp0[0] + dp0[1];
			dp1[2] = dp1[0] + dp1[1];
			dp0[0] = dp0[1];
			dp1[0] = dp1[1];
			dp0[1] = dp0[2];
			dp1[1] = dp1[2];
		}
		cout << dp0[2] << ' ' << dp1[2] << endl;
	}

	return 0;
}
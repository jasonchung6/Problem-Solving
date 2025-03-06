#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	cin >> N;

	int DP[1001] = { 0, };
	DP[1] = 1;
	DP[2] = 3;
	
	for (int i = 3; i <= N; ++i)
	{
		DP[i] = ((DP[i - 2] * 2) + DP[i - 1]) % 10007;
	}

	cout << DP[N];

	return 0;
}
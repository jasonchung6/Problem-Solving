#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	long long DP[91] = { 0, };
	DP[1] = 1; //1
	DP[2] = 1; //10

	for (int i = 3; i <= N; ++i)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N];

	return 0;
}
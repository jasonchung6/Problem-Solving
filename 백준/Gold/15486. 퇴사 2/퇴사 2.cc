#include <iostream>
using namespace std;

int DP[1'500'001] = { 0, };
int TP[1'500'001][2] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> TP[i][0] >> TP[i][1];
	}
	
	for (int i = N; i > 0; --i)
	{
		int deadline = TP[i][0] + i - 1;
		if (deadline <= N)
		{
			DP[i] = max(DP[i + 1], (DP[deadline + 1] + TP[i][1]));
		}
		else
		{
			DP[i] = DP[i + 1];
		}
	}

	cout << DP[1];

	return 0;
}
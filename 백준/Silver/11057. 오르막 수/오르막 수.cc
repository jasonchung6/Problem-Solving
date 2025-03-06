#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int ANS = 0;
	cin >> N;

	int DP[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{ 
			DP[j] += DP[j - 1];
			DP[j] %= 10'007;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		ANS += DP[i];
	}

	cout << ANS % 10'007;

	return 0;
}
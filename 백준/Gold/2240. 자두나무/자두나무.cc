#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int W;
	int tree[1001] = {0,};
	int DP[1001][31][2] = {0,}; //T, W

	cin >> T >> W;
	for (int i = 1; i <= T; ++i)
	{
		cin >> tree[i];
	}

	DP[1][0][0] = tree[1] == 1 ? 1 : 0;
	DP[1][1][1] = tree[1] == 2 ? 1 : 0;

	for (int i = 2; i <= T; ++i)
	{
		if (tree[i] == 1)
		{
			DP[i][0][0] = DP[i - 1][0][0] + 1;
			DP[i][0][1] = DP[i - 1][0][1];
		}
		else
		{
			DP[i][0][0] = DP[i - 1][0][0];
			DP[i][0][1] = DP[i - 1][0][1] + 1;
		}
		for (int j = 1; j <= W; j++)
		{
			if (tree[i] == 1)
			{
				DP[i][j][0] = max(DP[i - 1][j][0], DP[i - 1][j - 1][1]) + 1;
				DP[i][j][1] = max(DP[i - 1][j - 1][0], DP[i - 1][j][1]);
			}
			else
			{
				DP[i][j][0] = max(DP[i - 1][j][0], DP[i - 1][j - 1][1]);
				DP[i][j][1] = max(DP[i - 1][j - 1][0], DP[i - 1][j][1]) + 1;
			}
		}
	}

	int ANS = -1;
	for (int i = 0; i <= 31; i++) {
		ANS = max(ANS, max(DP[T][i][0], DP[T][i][1]));
	}

	cout << ANS;

	return 0;
}
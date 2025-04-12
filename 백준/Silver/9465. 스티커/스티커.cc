#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		vector<vector<int>> sticker(4, vector<int>(N, 0));
		for (int i = 0; i < N; ++i)
		{
			cin >> sticker[0][i];
		}
		for (int i = 0; i < N; ++i)
		{
			cin >> sticker[1][i];
		}
		if (N == 1)
		{
			if (sticker[0][0] > sticker[1][0])
			{
				cout << sticker[0][0] << '\n';
			}
			else
			{
				cout << sticker[1][0] << '\n';
			}
			continue;
		}
		sticker[2][0] = sticker[0][0];
		sticker[3][0] = sticker[1][0];
		sticker[2][1] = sticker[1][0] + sticker[0][1];
		sticker[3][1] = sticker[0][0] + sticker[1][1];
		for (int i = 2; i < N; ++i)
		{
			if (sticker[2][i - 1] > sticker[2][i - 2])
			{
				sticker[3][i] = sticker[2][i - 1] + sticker[1][i];
			}
			else
			{
				sticker[3][i] = sticker[2][i - 2] + sticker[1][i];
			}
			if (sticker[3][i - 1] > sticker[3][i - 2])
			{
				sticker[2][i] = sticker[3][i - 1] + sticker[0][i];
			}
			else
			{
				sticker[2][i] = sticker[3][i - 2] + sticker[0][i];
			}
		}

		if (sticker[2][N - 1] > sticker[3][N - 1])
		{
			cout << sticker[2][N - 1] << '\n';
		}
		else
		{
			cout << sticker[3][N - 1] << '\n';
		}
	}

	return 0;
}
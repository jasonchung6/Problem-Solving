#include <iostream>
using namespace std;

int main()
{
	int n = 0, m = 0, temp_cng = 0, low = 2100000000;
	char board[50][50], tempBW;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			for (int x = 1; x < 9; x++)
			{
				for (int y = 1; y < 9; y++)
				{
					if ((x + y) % 2 == 0)
						tempBW = 'B';
					else
						tempBW = 'W';
					if (tempBW != board[x + i][y + j])
						temp_cng++;
				}
			}
			if (temp_cng < low)
				low = temp_cng;
			temp_cng = 0;
			for (int x = 1; x < 9; x++)
			{
				for (int y = 1; y < 9; y++)
				{
					if ((x + y) % 2 == 0)
						tempBW = 'W';
					else
						tempBW = 'B';
					if (tempBW != board[x + i][y + j])
						temp_cng++;
				}
			}
			if (temp_cng < low)
				low = temp_cng;
			temp_cng = 0;

		}
	}
	cout << low;
	return 0;
}
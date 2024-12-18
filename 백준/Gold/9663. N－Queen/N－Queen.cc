#include <iostream>
#include <vector>

using namespace std;
vector<int> colVec;
vector<bool> validCol;
int N = 0, ANS = 0;

bool isValidCol(int row, int col)
{
	for (int i = 0; i < colVec.size(); i++)
	{
		if (row - i == col - colVec[i] || row - i == colVec[i] - col)
		{
			return false;
		}
	}
	return true;
}

void backTrack(int row, int col)
{
	++row;
	if (row == N - 1)
	{
		for (int i = 0; i < N; i++)
		{
			if (validCol[i] && isValidCol(row, i))
			{
				++ANS;
			}
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (validCol[i] && isValidCol(row, i))
			{
				colVec.push_back(i);
				validCol[i] = false;
				backTrack(row, i);
				validCol[i] = true;
				colVec.pop_back();
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}

	validCol = vector<bool>(N, 1);

	for (int i = 0; i < N; i++)
	{
		colVec.push_back(i);
		validCol[i] = false;
		backTrack(0, i);
		validCol[i] = true;
		colVec.pop_back();
	}

	cout << ANS;

	return 0;
}
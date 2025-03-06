#include <iostream>
using namespace std;

int DP[1'000'001] = { 0, };
int map[1'000'001] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;

	map[0] = 0;
	map[1] = 0;
	map[2] = 1;
	map[3] = 1;

	for (int i = 4; i <= N; i++)
	{
		DP[i] = DP[i - 1] + 1;
		map[i] = i - 1;
		if (i % 2 == 0)
		{
			if (DP[i] > DP[i / 2] + 1)
			{
				DP[i] = DP[i / 2] + 1;
				map[i] = i / 2;
			}
		}
		if (i % 3 == 0)
		{
			if (DP[i] > DP[i / 3] + 1)
			{
				DP[i] = DP[i / 3] + 1;
				map[i] = i / 3;
			}
		}
	}
	cout << DP[N] << "\n";
	
	while (N != 0)
	{
		cout << N << " ";
		N = map[N];
	}

	return 0;
}
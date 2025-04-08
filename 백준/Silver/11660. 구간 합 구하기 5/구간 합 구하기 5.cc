#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> num(N, vector<int>(N, 0));
	vector<vector<int>> rowSum(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> rowSum[i][j];
			rowSum[i][j] += rowSum[i][j - 1];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int x1, y1, x2, y2;
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		--y1;
		for (int j = x1; j <= x2; ++j)
		{
			ans += rowSum[j][y2] - rowSum[j][y1];
		}

		cout << ans << "\n";
	}

	return 0;
}
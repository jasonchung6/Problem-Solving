#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(3, 0));

	for (int i = 0; i < n; i++)
		cin >> vec[i][0] >> vec[i][1] >> vec[i][2]; //RGB

	for (int i = 1; i < n; i++)
	{
		vec[i][0] += min(vec[i - 1][1], vec[i - 1][2]);
		vec[i][1] += min(vec[i - 1][0], vec[i - 1][2]);
		vec[i][2] += min(vec[i - 1][0], vec[i - 1][1]);
	}

	cout << min({vec[n - 1][0], vec[n - 1][1], vec[n - 1][2]});

	return 0;
}
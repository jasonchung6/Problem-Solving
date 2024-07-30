#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, ans = 0;
	cin >> n >> m;

	vector<vector<int>> planet(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> planet[i][j];

	vector<vector<int>> comp{ planet };
	for (int i = 0; i < n; ++i) {
		sort(comp[i].begin(), comp[i].end());
		for (int j = 0; j < m; ++j)
			planet[i][j] = lower_bound(comp[i].begin(), comp[i].end(), planet[i][j]) - comp[i].begin();
		for (int k = 0; k < i; ++k)
			if (planet[k] == planet[i])
				ans++;
	}						

	cout << ans;

	return 0;
}
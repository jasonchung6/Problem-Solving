#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans, time;
	cin >> n;

	vector<pii> vec(n);

	for (int i = 0; i < n; ++i)
		cin >> vec[i].first >> vec[i].second;

	//sort(vec.begin(), vec.end());
	sort(vec.begin(), vec.end(), [](const pii& a, const pii& b) {
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
		});

	time = vec[0].second;
	ans = 1;

	for (int i = 1; i < n; ++i)
	{
		if (vec[i].first >= time)
		{
			++ans;
			time = vec[i].second;
		}
	}

	cout << ans;

	return 0;
}
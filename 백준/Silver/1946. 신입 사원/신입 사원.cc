#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef pair<int, int> pii;
constexpr int SIZE = 100000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, temp, ans;
	cin >> t;

	while (t--) {
		cin >> n;
		vector<pii> vec(n);
		for (int i = 0; i < n; ++i)
			cin >> vec[i].first >> vec[i].second;

		sort(vec.begin(), vec.end(), [](const pii& a, const pii& b) {
			return a.first < b.first;
			});

		temp = vec[0].second;
		ans = 0;
		for (int i = 0; i < n; ++i) {
			if (temp >= vec[i].second)
			{
				++ans;
				temp = vec[i].second;
			}
		}


		cout << ans << endl;
	}

	return 0;
}
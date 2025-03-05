#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> seq(N, 0);
	int cnt[100'001] = { 0, };

	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
	}

	int start = 0;
	int end = 0;
	int ans = 0;
	
	while (start < N) {
		if (cnt[seq[start]] != K) {
			cnt[seq[start]]++;
			start++;
		}
		else {
			cnt[seq[end]]--;
			end++;
		}
		ans = max(ans, start - end);
	}

	cout << ans;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, last = 0;
	cin >> N;
	vector<int> seq(N + 1);
	vector<int> LIS(N + 1);
	for (int i = 0; i < N; ++i)
	{
		cin >> seq[i];
	}
	LIS[0] = seq[0];

	for (int i = 0; i < N; ++i)
	{
		if (seq[i] > LIS[last])
		{
			LIS[++last] = seq[i];
		}
		else
		{
			int idx = lower_bound(LIS.begin(), LIS.begin() + last, seq[i]) - LIS.begin();
			LIS[idx] = seq[i];
		}
	}

	cout << last + 1;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> seq(N);
	vector<int> pos(N);
	vector<int> LIS;

	for (int i = 0; i < N; ++i)
	{
		cin >> seq[i];
	}

	LIS.push_back(seq[0]);
	pos[0] = 0;

	for (int i = 1; i < N; ++i)
	{
		if (seq[i] > LIS.back())
		{
			LIS.push_back(seq[i]);
			pos[i] = LIS.size() - 1;
		}
		else
		{
			auto it = lower_bound(LIS.begin(), LIS.end(), seq[i]);
			*it = seq[i];
			pos[i] = it - LIS.begin();
		}
	}

	cout << LIS.size() << '\n';

	vector<int> ANS;
	int target_idx = LIS.size() - 1;

	for (int i = N - 1; i >= 0; --i)
	{
		if (pos[i] == target_idx)
		{
			ANS.push_back(seq[i]);
			target_idx--;
		}
	}

	for (int i = ANS.size() - 1; i >= 0; --i)
	{
		cout << ANS[i] << ' ';
	}
	cout << '\n';

	return 0;
}

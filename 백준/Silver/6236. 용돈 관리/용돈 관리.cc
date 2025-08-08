#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	int N, M, K;
	int start = 0, end = 0, mid;
	int bal;
	cin >> N >> M;
	vector<int> NUMS(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> NUMS[i];
		start = max(start, NUMS[i]);
		end += NUMS[i];
	}

	while (start <= end)
	{
		mid = (start + end) / 2;
		bal = mid;
		int count = 1;
		for (int i = 0; i < N; ++i)
		{
			if (bal < NUMS[i])
			{
				++count;
				bal = mid - NUMS[i];
			}
			else
			{
				bal -= NUMS[i];
			}
		}

		if (count > M)
		{
			start = mid + 1;
			K = mid;
		}
		else
		{
			end = mid - 1;
			K = mid;
		}
	}

	cout << K;

 	return 0;
}
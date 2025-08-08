#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ANS = 0;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < N; ++i)
	{
		int start = 0, end = N - 1;
		while (start < end) {
			if (nums[start] + nums[end] < nums[i])
			{
				++start;
			}
			else if (nums[start] + nums[end] > nums[i])
			{
				--end;
			}
			else
			{
				if (start != i && end != i)
				{
					++ANS;
					break;
				}
				else if (start == i)
				{
					++start;
				}
				else if (end == i)
				{
					--end;
				}
			}
		}
	}

	cout << ANS;

	return 0;
}
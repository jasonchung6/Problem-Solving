#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
constexpr int SIZE = 200'001;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, k2, temp;
	cin >> n >> k;

	k2 = 2 * k;
	int vec[SIZE];
	fill(vec, vec + SIZE, -1);
	deque<int> dq;
	dq.push_back(n);
	vec[n] = 0;

	while (!dq.empty())
	{
 		n = dq.front();
		dq.pop_front();
		temp = 2 * n;
		if (temp < k2 && vec[temp] == -1)
		{
			vec[temp] = vec[n];
			dq.push_front(temp);
		}
		temp = n - 1;
		if (temp >= 0 && vec[temp] == -1)
		{
			vec[temp] = vec[n] + 1;
			dq.push_back(temp);
		}
		temp = n + 1;
		if (temp <= 100'000 && vec[temp] == -1)
		{
			vec[temp] = vec[n] + 1;
			dq.push_back(temp);
		}
	}

 	std::cout << vec[k];

	return 0;
}
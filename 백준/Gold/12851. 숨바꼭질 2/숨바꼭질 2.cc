#include <iostream>
#include <queue>
using namespace std;

constexpr int SIZE = 200'001;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, k2, cur, temp, ans = 0;
	cin >> n >> k;

	k2 = 2 * k;
	int vec[SIZE + 1] = { 0, };
	queue<int> q;
	q.push(n);
	vec[n] = 0;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		if (cur == k)
		{
			++ans;
			continue;
		}

		temp = cur + 1;
		if (temp <= SIZE)
		{
			if (vec[temp] == 0 || vec[temp] == vec[cur] + 1)
			{
				vec[temp] = vec[cur] + 1;
				q.push(temp);
			}
		}

		temp = cur - 1;
		if (temp >= 0)
		{
			if (vec[temp] == 0 || vec[temp] == vec[cur] + 1)
			{
				vec[temp] = vec[cur] + 1;
				q.push(temp);
			}
		}

		temp = 2 * cur;
		if (temp < k2)
		{
			if (vec[temp] == 0 || vec[temp] == vec[cur] + 1)
			{
				vec[temp] = vec[cur] + 1;
				q.push(temp);
			}
		}
	}

	std::cout << vec[k] << endl << ans;

	return 0;
}